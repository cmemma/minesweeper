#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include"gameboard.cpp"
#include <QGridLayout>
#include <QPushButton>
#include<QString>
#include<vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::secTimer);

    set_pictures();
    init_buttons();

}

void MainWindow::handle_button_clicks()
{
    // goes through all the buttons and finds out which one is the signal sender
    for (int y = 0 ; y < BOARD_SIDE; ++y){
        for (int x = 0 ; x < BOARD_SIDE ; ++x ) {

            QPushButton* button = Qbuttons.at(y).at(x);

            if (button == sender()) {

                Square flagged_square = board_.getSquare(x, y);
                //user is inputting a flag
                if (flag_is_on_){

                    if (flagged_square.hasFlag()){
                        button->setIcon(QIcon());
                        flagged_square.removeFlag();

                    } else {
                        button->setIcon(flag_image_);
                        flagged_square.addFlag();

                    }
                    board_.setSquare(flagged_square,x,y);

                // user is inputting an questionmark
                }else if (question_mark){

                    if (flagged_square.hasQuestion()){
                        button->setIcon(QIcon());
                        flagged_square.removeQuestion();

                    } else {
                        button->setIcon(questionmark_image_);
                        flagged_square.addQuestion();

                    }
                    board_.setSquare(flagged_square,x,y);
                // user is opening the square
                } else {
                    play_game(x, y);
                }
                check_ending();
            }
        }
    }
}

void MainWindow::init_buttons()
{
    ui->flag_button->setIcon(click_image_);
    for (int y = 0 ; y < BOARD_SIDE; ++y){

        std::vector<QPushButton*> line;

        for (int x = 0 ; x < BOARD_SIDE ; ++x ) {

            QPushButton* pushButton = new QPushButton(this);

            pushButton->setCheckable(true);
            pushButton->setChecked(true);
            pushButton->setStyleSheet("color: black;");

            line.push_back(pushButton);

            pushButton->setGeometry(2 * MARGIN + x * (BUTTON_WIDTH+MARGIN),
                                    2 * MARGIN + y * (BUTTON_HEIGTH + MARGIN),
                                    BUTTON_WIDTH,
                                    BUTTON_HEIGTH);

            connect(pushButton, &QPushButton::clicked,
                    this, &MainWindow::handle_button_clicks);
        }
        Qbuttons.push_back(line);
    }

}

void MainWindow::play_game(int x, int y)
{
    Square new_square = board_.getSquare(x,y);
    new_square.open();
    board_.setSquare(new_square,x,y);

    if (new_square.hasMine()){
        dead();
    } else {
        // goes through all the squares and checks what squares are opened
        // then opens the equivalent button
        for (int y = 0 ; y < BOARD_SIDE; ++y){
            for (int x = 0 ; x < BOARD_SIDE ; ++x ) {
                if (board_.getSquare(x,y).isOpen() and !board_.getSquare(x,y).hasMine()){

                    int adjacent = board_.getSquare(x,y).countAdjacent();

                    if (adjacent > 0) {
                        Qbuttons.at(y).at(x)->setText(QString::number(adjacent));
                    }
                    Qbuttons.at(y).at(x)->setCheckable(true);
                    Qbuttons.at(y).at(x)->setChecked(true);
                    Qbuttons.at(y).at(x)->setDisabled(true);
                 }
            }
        }
    }
}


void MainWindow::check_ending()
{
    bool game_ended = true;
    for (int y = 0 ; y < BOARD_SIDE; ++y){
        for (int x = 0 ; x < BOARD_SIDE ; ++x ) {
            // if square has a mine but is not flagged, game is not won
            if(board_.getSquare(x,y).hasMine()) {
                if(!board_.getSquare(x,y).hasFlag()){
                    game_ended = false;
                }
            }
        }
    }
    if (game_ended){
        ui->gameEndingText->setText("Gongratulations! You have won the game!");
        timer->stop();
        // when game is won, all buttons are disabled
        for (int y = 0 ; y < BOARD_SIDE; ++y){
            for (int x = 0 ; x < BOARD_SIDE ; ++x ) {
                Qbuttons.at(y).at(x)->setDisabled(true);
            }
        }
    }
}

void MainWindow::dead()
{
    timer->stop();
    // when dead, all mine buttons are opened and all buttons disabled
    for (int y = 0 ; y < BOARD_SIDE; ++y){
        for (int x = 0 ; x < BOARD_SIDE ; ++x ) {
            if(board_.getSquare(x,y).hasMine()) {
                Qbuttons.at(y).at(x)->setIcon(mine_image_);
                Qbuttons.at(y).at(x)->setCheckable(true);
                Qbuttons.at(y).at(x)->setChecked(true);

                ui->gameEndingText->setText("You exploded!");
            }
            Qbuttons.at(y).at(x)->setDisabled(true);
        }
    }
}


void MainWindow::on_flag_button_clicked()
{
    // after flag, the buttons offers a question mark
    if(flag_is_on_){
        ui->flag_button->setIcon(questionmark_image_);
        flag_is_on_ = false;
        question_mark = true;
    // after question mark user can open squares
    } else if (question_mark) {
        ui->flag_button->setIcon(click_image_);
        question_mark = false;
    } else {
        ui->flag_button->setIcon(flag_image_);
        flag_is_on_ = true;
    }
}


void MainWindow::on_seedNumberBox_valueChanged(int arg1)
{
    if(arg1 == 0){
        seed_ = time(NULL);
    } else {
        seed_ = arg1;
    }
}

void MainWindow::on_startButton_clicked()
{
    board_.init(seed_);
    timer->start(1000);

    // start button enables all buttons
    for (auto& button_line : Qbuttons){
        for (auto& button : button_line){
            button->setChecked(false);
            button->setCheckable(false);
            button->setEnabled(true);
        }
    }
    // during game seed number can't be inputted or game started again
    ui->startButton->setEnabled(false);
    ui->seedNumberBox->setEnabled(false);
}


void MainWindow::on_resetButton_clicked()
{
    ui->startButton->setEnabled(true);
    ui->seedNumberBox->setEnabled(true);
    ui->gameEndingText->setText("");

    timer->stop();
    ui->secTimerLCD->display(0);
    ui->minTimerLCD->display(0);

    // creates a new board of squares
    GameBoard board_new;
    board_ = board_new;

    // deletes all markings from buttons and disables them
    for (auto& button_line : Qbuttons){
        for (auto& button : button_line){
            button->setIcon(QIcon());
            button->setText("");
            button->setCheckable(true);
            button->setChecked(true);
            button->setDisabled(true);
        }
    }
}

void MainWindow::secTimer()
{
    int seconds = ui->secTimerLCD->intValue();
    int minutes = ui->minTimerLCD->intValue();
    ++seconds;
    if (seconds == 60){
        seconds = 0;
        ++minutes;
    }
    ui->secTimerLCD->display(seconds);
    ui->minTimerLCD->display(minutes);

}

void MainWindow::set_pictures()
{
    // Defining where the images can be found and what kind of images they are
    const std::string PREFIX(":/new/prefix1/resources/");
    const std::string SUFFIX(".png");


    // Converting image (png) to a pixmap
    std::string mine_file = PREFIX + "mine" + SUFFIX;
    QPixmap mine_image(QString::fromStdString(mine_file));

    std::string flag_file = PREFIX + "flag" + SUFFIX;
    QPixmap flag_image(QString::fromStdString(flag_file));

    std::string question_file = PREFIX + "questionmark" + SUFFIX;
    QPixmap questionmark_image(QString::fromStdString(question_file));

    std::string click_file = PREFIX + "click" + SUFFIX;
    QPixmap click_image(QString::fromStdString(click_file));

    // Scaling the pixmap
    mine_image_ = mine_image.scaled(BUTTON_WIDTH, BUTTON_HEIGTH);
    flag_image_ = flag_image.scaled(BUTTON_WIDTH, BUTTON_HEIGTH);
    questionmark_image_ = questionmark_image.scaled(BUTTON_WIDTH, BUTTON_HEIGTH);
    click_image_ = click_image.scaled(BUTTON_WIDTH, BUTTON_HEIGTH);

}




MainWindow::~MainWindow()
{
    for (auto& button_line : Qbuttons){
        for (auto& button : button_line){
            delete button;
        }
    }
    delete timer;
    delete ui;
}


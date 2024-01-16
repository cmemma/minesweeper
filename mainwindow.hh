/*
#############################################################################
# COMP.CS.110 Programming 2: Autumn 2021                                    #
# Project4: Minesweeper                                                     #
# File: mainwindow.hh                                                       #
# Description: Describes the mainwindow of the minesweeper game.            #
#       Mainwindow contains gameboard, startbutton, reset button, timer,    #
#       button to change the outcome of button click.                       #
#############################################################################
*/

#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include"gameboard.hh"
#include<QPushButton>
#include<QTimer>
#include<QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    //if flag button is clicked, it changes the reaction of a gameboard square when
    //it is clicked.
    void on_flag_button_clicked();

    //changes the seed value that randomizes the mine placement
    void on_seedNumberBox_valueChanged(int arg1);

    //enables the buttons and starts timer
    void on_startButton_clicked();

    //resets timer and disables and turns the buttons off
    void on_resetButton_clicked();

private:
    Ui::MainWindow *ui;

    GameBoard board_;

    //all the gameboard buttons are saved into same structure as board_ squares
    //so that they can be compared
    std::vector<std::vector<QPushButton*>> Qbuttons;

    //next two bools describe what the user wants to do with the button click
    bool flag_is_on_ = false;
    bool question_mark = false;

    int seed_ = 0;
    QTimer* timer;

    // Space between elements, both horizontally and vertically
    const int MARGIN = 0;

    // Constants for push buttons
    const int BUTTON_WIDTH = 320/BOARD_SIDE;
    const int BUTTON_HEIGTH = 320/BOARD_SIDE;

    QPixmap mine_image_;
    QPixmap flag_image_;
    QPixmap questionmark_image_;
    QPixmap click_image_;

    // when gameboard buttons are clicked, this function checks if user is putting flag or
    // question mark or if user wants to open button. If opening, function calls the
    // opening function and checks if user has won.
    void handle_button_clicks();

    // creates the gameboard buttons
    void init_buttons();

    // checks if square has mine. if not, opens and calculates how many adjacent mines the
    // square has and then pushes the button down and presents the number of adjacent mines
    void play_game(int x, int y);

    // checks whether all the mines have been flagged
    void check_ending();

    // if user hits mine, all the buttons are disabled and mine buttons are opened
    void dead();

    // handles the timer
    void secTimer();

    void set_pictures();
};
#endif // MAINWINDOW_HH

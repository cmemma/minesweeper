/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *startButton;
    QPushButton *resetButton;
    QPushButton *flag_button;
    QTextBrowser *gameEndingText;
    QSpinBox *seedNumberBox;
    QLabel *label;
    QLCDNumber *minTimerLCD;
    QLCDNumber *secTimerLCD;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(490, 349);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(188, 224, 245);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(340, 70, 61, 28));
        startButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 163, 163);"));
        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(410, 70, 61, 28));
        resetButton->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 163, 163);"));
        flag_button = new QPushButton(centralwidget);
        flag_button->setObjectName(QString::fromUtf8("flag_button"));
        flag_button->setGeometry(QRect(340, 170, 41, 41));
        flag_button->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 163, 163);"));
        gameEndingText = new QTextBrowser(centralwidget);
        gameEndingText->setObjectName(QString::fromUtf8("gameEndingText"));
        gameEndingText->setGeometry(QRect(340, 220, 141, 71));
        gameEndingText->setStyleSheet(QString::fromUtf8("border-color: rgb(188, 224, 245);"));
        seedNumberBox = new QSpinBox(centralwidget);
        seedNumberBox->setObjectName(QString::fromUtf8("seedNumberBox"));
        seedNumberBox->setGeometry(QRect(340, 30, 45, 29));
        seedNumberBox->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 163, 163);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 10, 101, 20));
        minTimerLCD = new QLCDNumber(centralwidget);
        minTimerLCD->setObjectName(QString::fromUtf8("minTimerLCD"));
        minTimerLCD->setGeometry(QRect(340, 110, 64, 23));
        minTimerLCD->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 163, 163);"));
        secTimerLCD = new QLCDNumber(centralwidget);
        secTimerLCD->setObjectName(QString::fromUtf8("secTimerLCD"));
        secTimerLCD->setGeometry(QRect(410, 110, 64, 23));
        secTimerLCD->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 163, 163);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(360, 140, 31, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(430, 140, 31, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 490, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        flag_button->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Seed number:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "min", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "sec", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

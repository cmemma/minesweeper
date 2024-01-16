/*
 * COMP.CS.110 Programming 2, Autumn 2021
 * Project4: Minesweeper GUI
 *
 * Desc:
 *   This program contains a graphic user interface minesweeper game. The gameboard consists of
 *   buttons that the user can push down to see underneath. User can also flag the squares
 *   that they think contain a mine. If user is unsure about a square, they can mark it with a
 *   questionmark. Before starting the game, user can input a wanted seednumber to change the
 *   placement of the mines. If no seed is inputted, the seed is 0. After inputting seed, user
 *   can start the game by clicking start button. This also starts the timer. If user has flagged
 *   all of the mines, they win and game stops. If user hits a mine, they lose and game stops. Numbers
 *   on mines tell, how many mines are in the 8 surrounding squares. If button is empty, there is no mines.
 *   User can reset the game anytime by clicking the reset button. After that the seed can be inputted
 *   again and game can be started. The timer resets also.
 *
 * Program author
 * Name: Emma Mannila
 * Student number: H299896
 * UserID: cmemma
 * E-Mail: emma.mannila@tuni.fi
 *
 * */

#include "mainwindow.hh"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

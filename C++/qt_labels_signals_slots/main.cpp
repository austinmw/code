//#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <QPushButton>


int main(int argc, char *argv[])
{
    QApplication prog(argc, argv); // main program object
    //  MainWindow w;
    //  w.show();

    /* // QLabel
    QLabel *label = new QLabel("Gametime!");
    label->show();
    */

    // QPushBotton
    QPushButton *button = new QPushButton("Quit the program!");

    // signals and slots allow you to add functionality to the button
    QObject::connect(button, SIGNAL(clicked()), &prog, SLOT(quit()));
    // when user does thing in signal, slot thing happens
    button->show();



    return prog.exec(); // starts main event loop
}



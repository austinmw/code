#include "findcrap.h"
#include "ui_findcrap.h"
#include <QFile>           // need this
#include <QTextStream>     // and this

Findcrap::Findcrap(QWidget *parent) : QWidget(parent), ui(new Ui::Findcrap) {
    ui->setupUi(this);
    getTextFile();
}

Findcrap::~Findcrap() {
    delete ui;
}

void Findcrap::on_goButton_clicked() {
    QString word = ui->lineEdit->text(); // get string from bottom bar
    ui->textEdit->find(word, QTextDocument::FindWholeWords);

}


void Findcrap::getTextFile() {

    // open file
    QFile myFile(":/crap.txt");
    myFile.open(QIODevice::ReadOnly);

    // convert file to a stream
    QTextStream textStream(&myFile);
    QString line = textStream.readAll();
    myFile.close();

    // display text in text box
    ui->textEdit->setPlainText(line);

    // store cursor in variable
    QTextCursor textCursor =ui->textEdit->textCursor();
    // move text cursor
    textCursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);


    // load file: File->New File or Project->Qt->Qt Resource File
    // create file name, next, finish
    // add prefixes:  /
    // add files: find and add the file
}





/*
  Designer
  Cmd+A (all)
  Ctrl+Shift+H (horizontal)
  Cmd+L (layout)
  right-click, go to slot
  edit findcrap.h

*/

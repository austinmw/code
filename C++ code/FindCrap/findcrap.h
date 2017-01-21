#ifndef FINDCRAP_H
#define FINDCRAP_H

#include <QWidget>

// namespaces allow you to grp things like classes together
namespace Ui {
class Findcrap;
}

class Findcrap : public QWidget
{
    Q_OBJECT  // required macro

public:
    explicit Findcrap(QWidget *parent = 0);   // constructor (set to null, has no parent)
    ~Findcrap();  // deconstructor

private slots:
    void on_goButton_clicked();

private:
    Ui::Findcrap *ui;   // overall interface
    void getTextFile();      // created this to load in txt file


};

#endif // FINDCRAP_H

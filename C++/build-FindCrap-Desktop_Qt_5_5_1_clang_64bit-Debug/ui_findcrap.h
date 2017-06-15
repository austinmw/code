/********************************************************************************
** Form generated from reading UI file 'findcrap.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDCRAP_H
#define UI_FINDCRAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Findcrap
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *goButton;

    void setupUi(QWidget *Findcrap)
    {
        if (Findcrap->objectName().isEmpty())
            Findcrap->setObjectName(QStringLiteral("Findcrap"));
        Findcrap->resize(400, 300);
        verticalLayout = new QVBoxLayout(Findcrap);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        textEdit = new QTextEdit(Findcrap);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Findcrap);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(Findcrap);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        goButton = new QPushButton(Findcrap);
        goButton->setObjectName(QStringLiteral("goButton"));

        horizontalLayout->addWidget(goButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Findcrap);

        QMetaObject::connectSlotsByName(Findcrap);
    } // setupUi

    void retranslateUi(QWidget *Findcrap)
    {
        Findcrap->setWindowTitle(QApplication::translate("Findcrap", "Findcrap", 0));
        label->setText(QApplication::translate("Findcrap", "search for:", 0));
        goButton->setText(QApplication::translate("Findcrap", "Go!", 0));
    } // retranslateUi

};

namespace Ui {
    class Findcrap: public Ui_Findcrap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDCRAP_H

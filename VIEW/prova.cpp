#include "prova.h"

Prova::Prova(QWidget *parent) : QWidget(parent)
{
    acc = new QGridLayout();
    bbb= new QGroupBox("booooooom");
    QLabel* l = new QLabel("L:");
    QLineEdit* length = new QLineEdit();

    acc->addWidget(l,0,0);
    acc->addWidget(length,0,1);

    setLayout(acc);

}

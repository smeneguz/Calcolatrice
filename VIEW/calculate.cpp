#include "calculate.h"

Calculate::Calculate(BusinessLogic *l, QWidget *parent) : QWidget(parent), log(l)
{
    //first operand
    QLabel* l1o = new QLabel(tr("first Operand"));
    firsto = new QLineEdit();
    add1o = new QPushButton(tr("add here"));

    //operator
    op = new Operatori();

    //second operand
    QLabel* l2o = new QLabel(tr("second Operand"));
    secondo = new QLineEdit();
    add2o = new QPushButton(tr("add here"));

    //struct layout fisrt part
    struttura = new QGridLayout(this);
    struttura->addWidget(l1o, 0, 0);
    struttura->addWidget(firsto, 1, 0);
    struttura->addWidget(add1o, 2, 0);
    struttura->addWidget(op, 0, 1, 3, 1);
    struttura->addWidget(l2o, 0, 2);
    struttura->addWidget(secondo, 1, 2);
    struttura->addWidget(add2o, 2, 2);

    // uguale
    uguale = new QPushButton(tr("="), this);

    //risultato
    QLabel* rl = new QLabel(tr("result"));
    risultato = new QLineEdit();
    save = new QPushButton(tr("Save"));

    //clear
    QPushButton* clearP = new QPushButton(tr("Clear"), this);

    //struct second part
    struttura->addWidget(uguale, 1, 3);
    struttura->addWidget(clearP, 2, 3);
    struttura->addWidget(rl, 0, 4);
    struttura->addWidget(risultato, 1, 4);
    struttura->addWidget(save, 2, 4);

    //Connect Button
    connect(add1o, SIGNAL(clicked()), this, SLOT(addOp1()));
    connect(add2o, SIGNAL(clicked()), this, SLOT(addOp2()));
    connect(op, SIGNAL(operatorChanged()), this, SLOT(setOperator()));
    connect(uguale, SIGNAL(clicked()), this, SLOT(execute()));
    connect(clearP, SIGNAL(clicked()), this, SLOT(clear()));
    connect(save, SIGNAL(clicked()), this, SLOT(saveResult()));



}

void Calculate::setOperator()
{

}

void Calculate::addOp1()
{

}

void Calculate::addOp2()
{

}

void Calculate::execute()
{

}

void Calculate::clear()
{

}

void Calculate::saveResult()
{

}

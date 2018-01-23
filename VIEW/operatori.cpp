#include "operatori.h"

Operatori::Operatori(QWidget *parent) : QWidget(parent)
{
    struttura = new QGridLayout(this);
    selezione = -1; //univoco -> nessun operatore selezionato

    QGroupBox* groupBox = new QGroupBox(tr("Select Operator"));
    QGridLayout* structO = new QGridLayout(); //come vengono disposti i pulsanti di + - % *
    QRadioButton* add = new QRadioButton(tr("+"));
    QRadioButton* sub = new QRadioButton(tr("-"));
    QRadioButton* mult = new QRadioButton(tr("x"));
    QRadioButton* div = new QRadioButton(tr(":"));

    structO->addWidget(add, 0, 0);
    structO->addWidget(sub, 0, 1);
    structO->addWidget(mult, 1, 0);
    structO->addWidget(div, 1, 1);

    //connect pulsanti operazioni con slot appropriato
    connect(add, SIGNAL(clicked()), this, SLOT(selectSomma()));
    connect(sub, SIGNAL(clicked()), this, SLOT(selectSottrazione()));
    connect(mult, SIGNAL(clicked()), this, SLOT(selectMoltiplicazione()));
    connect(div, SIGNAL(clicked()), this, SLOT(selectDivisione()));

     groupBox->setLayout(structO);
     struttura->addWidget(groupBox, 0, 0);
}

int Operatori::getSelectedOperator() const
{
    return selezione;
}

void Operatori::selectSomma()
{
    selezione=0;
    emit operatorChanged();
}

void Operatori::selectSottrazione()
{
    selezione=1;
    emit operatorChanged();
}

void Operatori::selectMoltiplicazione()
{
    selezione=2;
    emit operatorChanged();
}

void Operatori::selectDivisione()
{
    selezione=3;
    emit operatorChanged();
}

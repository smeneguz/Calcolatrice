#include "newobject1d.h"

NewObject1D::NewObject1D(BusinessLogic l, QWidget *parent) : QWidget(parent), log(l)
{
    //si costruisce struttura a griglia
    struttura = new QGridLayout(this);
    // box con scritta che contiene tutti gli altri box per la creazione
    newLineBox = new QGroupBox(tr("Create new Object1D"));
    setWindowTitle(tr("Create new Object1D"));
    // box dove si setta lunghezza e risoluzione
    gridBox = new QGridLayout();

    //label
    QLabel* lung = new QLabel(tr("Length:"));
    length = new QLineEdit();
    QLabel* r = new QLabel(tr("Resolution:"));
    risoluzione = new QLineEdit();

    //posizionamento in griglia dei widget
    gridBox->addWidget(lung, 0, 0);
    gridBox->addWidget(length, 0, 1);
    gridBox->addWidget(r, 1, 0);
    gridBox->addWidget(risoluzione, 1, 1);

    // zona misure
    boxMisura = new QGroupBox();
    gridMisura = new QGridLayout(this);

    //bottoni settaggio misure
    QRadioButton* px = new QRadioButton(tr("px"));
    QRadioButton* cm = new QRadioButton(tr("cm"));
    QRadioButton* inch = new QRadioButton(tr("inch"));

    //This property holds whether the button is checked. Only checkable buttons can be checked. By default, the button is unchecked.
    px->setChecked(true);

    //px -> 0
    misura = 0;

    //posizionamento in griglia dei widget
    gridMisura->addWidget(px, 0, 0);
    gridMisura->addWidget(cm, 1, 0);
    gridMisura->addWidget(inch, 2, 0);

    boxMisura->setLayout(gridMisura);

    //bottone creazione
    create = new QPushButton(tr("Create"));

    //aggiungo al layout generale anche il bottone
    gridBox->addWidget(create, 2, 1);

    //sistemo il layout mettendo tutto insieme
    newLineBox->setLayout(gridBox);
    struttura->addWidget(newLineBox, 0, 0);

    connect(create, SIGNAL(clicked()), this, SLOT(saveLinea()));
    connect(px, SIGNAL(clicked()),this,SLOT(setPx()));
    connect(cm, SIGNAL(clicked()),this,SLOT(setCm()));
    connect(inch, SIGNAL(clicked()),this,SLOT(setInch()));
}

void NewObject1D::saveObject1D()
{

}

void NewObject1D::setPx()
{

}

void NewObject1D::setCm()
{

}

void NewObject1D::setInch()
{

}

#include "newobject2d.h"

NewObject2D::NewObject2D(BusinessLogic l, QWidget *parent) : QWidget(parent), log(l)
{
    //si costruisce struttura a griglia
    struttura = new QGridLayout(this);
    // box con scritta che contiene tutti gli altri box per la creazione
    newLineBox = new QGroupBox(tr("Create new Object2D"));
    setWindowTitle(tr("Create new Object2D"));
    // box dove si setta lunghezza e risoluzione
    gridBox = new QGridLayout();

    //label
    QLabel* lung = new QLabel(tr("Length:"));
    length = new QLineEdit();
    QLabel* h = new QLabel(tr("Height:"));
    height = new QLineEdit();
    QLabel* r = new QLabel(tr("Resolution:"));
    risoluzione = new QLineEdit();


    //posizionamento in griglia dei widget
    gridBox->addWidget(lung, 0, 0);
    gridBox->addWidget(length, 0, 1);
    boxGrid->addWidget(h,1,0);
    boxGrid->addWidget(height,1,1);
    gridBox->addWidget(r, 2, 0);
    gridBox->addWidget(risoluzione, 2, 1);

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
    gridBox->addWidget(boxMisura,0,2,2,1);

    //bottone creazione
    create = new QPushButton(tr("Create"));

    //aggiungo al layout generale anche il bottone
    gridBox->addWidget(create, 2, 1);

    //sistemo il layout mettendo tutto insieme
    newLineBox->setLayout(gridBox);
    struttura->addWidget(newLineBox, 0, 0);

    //connect
    connect(create, SIGNAL(clicked()), this, SLOT(saveObject2D()));
    connect(px, SIGNAL(clicked()),this,SLOT(setPx()));
    connect(cm, SIGNAL(clicked()),this,SLOT(setCm()));
    connect(inch, SIGNAL(clicked()),this,SLOT(setInch()));
}

void NewObject2D::saveObject2D()
{

}

void NewObject2D::setPx()
{

}

void NewObject2D::setCm()
{

}

void NewObject2D::setInch()
{

}

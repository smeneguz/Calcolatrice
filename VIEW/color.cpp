#include "color.h"

Color::Color(BusinessLogic *l, QWidget *parent) : QWidget(parent), logic(l)
{
    struttura = new QGridLayout(this);
    QGroupBox* boxNewLine = new QGroupBox(tr("create new color"));
    QGridLayout* boxGrid = new QGridLayout();

    // label for color
    QLabel* redLabel = new QLabel(tr("Red:"));
    QLabel* greenLabel = new QLabel(tr("Green:"));
    QLabel* blueLabel = new QLabel(tr("Blue:"));

    //slider
    Rslider = new ColorRange();
    Rslider->setRange(0,255);
    Gslider = new ColorRange();
    Gslider->setRange(0,255);
    Bslider = new ColorRange();
    Bslider->setRange(0,255);

    //set box color
    colorZone = new ColorZone();
    colorZone->setFixedSize(20,20);


    col = RGBHex(colorZone->getRed(),colorZone->getGreen(),colorZone->getBlue());
    QString s = QString::fromStdString("#"+col.getColor());
    colhex = new QLineEdit(s);
    create = new QPushButton(tr("Create"));

    //connect red slider when changed value -> set red slot
    connect(Rslider, SIGNAL(valueChanged(int)), this, SLOT(setRed(int)));
    //connect green slider when changed value ->set green slot
    connect(Gslider, SIGNAL(valueChanged(int)), this, SLOT(setGreen(int)));
    //connect blue slider when changed value ->set blue slot
    connect(Bslider, SIGNAL(valueChanged(int)), this, SLOT(setBlue(int)));
    //connect box color when edit line edit ->set text slot
    connect(colorZone, SIGNAL(colorChanged(QString)), colhex, SLOT(setText(QString)));
    // connect color when edit line edit -> change slider red
    connect(colhex, SIGNAL(textChanged(QString)), Rslider, SLOT(changeRed(QString)));
    // connect color when edit line edit -> change slider green
    connect(colhex, SIGNAL(textChanged(QString)), Gslider, SLOT(changeGreen(QString)));
    //connect color when edit line edit -> change slider blue
    connect(colhex, SIGNAL(textChanged(QString)), Bslider, SLOT(changeBlue(QString)));
    //when click on create -> new color created
    connect(create, SIGNAL(clicked()), this, SLOT(saveColor()));


    boxGrid->addWidget(redLabel,0,0);
    boxGrid->addWidget(greenLabel,1,0);
    boxGrid->addWidget(blueLabel,2,0);
    boxGrid->addWidget(Rslider,0,1);
    boxGrid->addWidget(Gslider,1,1);
    boxGrid->addWidget(Bslider,2,1);
    boxGrid->addWidget(colorZone,0,2,3,1);
    boxGrid->addWidget(colhex,3,1);
    boxGrid->addWidget(create,4,1);


    boxNewLine->setLayout(boxGrid);
    struttura->addWidget(boxNewLine,0,0);
}

void Color::setRed(int r)
{
    colorZone->setRed(r);
}

void Color::setGreen(int g)
{
    colorZone->setGreen(g);
}

void Color::setBlue(int b)
{
    colorZone->setBlue(b);
}

void Color::saveColor()
{
    logic->newColor(colhex->text().toStdString());
    emit colorAdded();
}

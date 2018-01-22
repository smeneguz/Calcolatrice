#include "selectdetails.h"

SelectDetails::SelectDetails(BusinessLogic *l, QWidget *parent) : QWidget(parent), log(l)
{
    //set pixel come misura predefinita
    misura = 0;
    //box dettagli e misura
    Box = new QGroupBox(tr("Details"));
    boxMisura = new QGroupBox();
    Grid = new QGridLayout();
    QGridLayout* GridMisura = new QGridLayout();

    QLabel* len = new QLabel(tr("length:"));
    QLabel* h = new QLabel(tr("height:"));
    QLabel* d = new QLabel(tr("depth:"));
    QLabel* risLabel = new QLabel(tr("Resolution:"));
    Grid->addWidget(len, 0, 0);
    Grid->addWidget(h, 1, 0);
    Grid->addWidget(d, 2, 0);
    Grid->addWidget(risLabel, 3, 0);

    //non modificabili
    length = new QLineEdit(tr(""));
    height = new QLineEdit(tr(""));
    depth = new QLineEdit(tr(""));
    ris = new QLineEdit(tr(""));
    length->setReadOnly(true);
    height->setReadOnly(true);
    depth->setReadOnly(true);
    ris->setReadOnly(true);

    Grid->addWidget(length, 0, 1);
    Grid->addWidget(height, 1, 1);
    Grid->addWidget(depth, 2, 1);
    Grid->addWidget(ris, 3, 1);

    //Misure
    QRadioButton* px = new QRadioButton(tr("pixel"));
    QRadioButton* cm = new QRadioButton(tr("cm"));
    QRadioButton* inch = new QRadioButton(tr("inch"));
    px->setChecked(true);
    GridMisura->addWidget(px, 0, 0);
    GridMisura->addWidget(cm, 1, 0);
    GridMisura->addWidget(inch, 2, 0);

    //inserimento box secondario misura in layout generale di details
    boxMisura->setLayout(GridMisura);
    Grid->addWidget(boxMisura, 0, 3, 2, 1);

    //Color
    QLabel* c = new QLabel(tr("Color:"));
    color = new QLineEdit(tr("#"));
    color->setReadOnly(true);
    colorZ->setFixedSize(50,50);
    colorZ->hide();
    //insert into general layout
    Grid->addWidget(c, 4, 0); //posiziono subito sotto risoluzione
    Grid->addWidget(color, 3, 1, 1, 2);
    Grid->addWidget(colorZ, 4, 3);

    //set struttura
    Box->setLayout(Grid);
    struttura = new QGridLayout(this);
    struttura->setColumnMinimumWidth(0, 300);
    struttura->addWidget(Box,0,0);
    length->setDisabled(true);
    height->setDisabled(true);
    depth->setDisabled(true);
    ris->setDisabled(true);
    color->setDisabled(true);
    boxMisura->setDisabled(true);
    colorZ->setDisabled(true);

    //Connect solo misure (resto non modificabile)
    connect(px, SIGNAL(clicked()),this,SLOT(setPx()));
    connect(cm, SIGNAL(clicked()),this,SLOT(setCm()));
    connect(inch, SIGNAL(clicked()),this,SLOT(setInch()));
    connect(this, SIGNAL(changeMeasureObj1D(QListWidgetItem*)),this,SLOT(updateObj1DD(QListWidgetItem*)));
    connect(this, SIGNAL(changeMeasureObj2D(QListWidgetItem*)),this,SLOT(updateObj2DD(QListWidgetItem*)));
    connect(this, SIGNAL(changeMeasureObj3D(QListWidgetItem*)),this,SLOT(updateObj3DD(QListWidgetItem*)));


}

void SelectDetails::setPx()
{
    misura = 0;
    QString le = QString(length->text());
    if(!(le.trimmed().isEmpty())){ //Object1D || Object2D || Object3D
        QString hi = QString(height->text());
        if(!(hi.trimmed().isEmpty())){ //Object2D || Object3D
            QString de = QString(depth->text());
            if(!(de.trimmed().isEmpty())) //Object3D
                emit updateObj3DD(selectedItem);
            else
                emit updateObj2DD(selectedItem); //Object2D
        }
        else
            emit updateObj1DD(selectedItem); //object1D

    }
}

void SelectDetails::setCm()
{
    misura = 1;
    QString le = QString(length->text());
    if(!(le.trimmed().isEmpty())){ //Object1D || Object2D || Object3D
        QString hi = QString(height->text());
        if(!(hi.trimmed().isEmpty())){ //Object2D || Object3D
            QString de = QString(depth->text());
            if(!(de.trimmed().isEmpty())) //Object3D
                emit updateObj3DD(selectedItem);
            else
                emit updateObj2DD(selectedItem); //Object2D
        }
        else
            emit updateObj1DD(selectedItem); //object1D

    }
}

void SelectDetails::setInch()
{
    misura = 2;
    QString le = QString(length->text());
    if(!(le.trimmed().isEmpty())){ //Object1D || Object2D || Object3D
        QString hi = QString(height->text());
        if(!(hi.trimmed().isEmpty())){ //Object2D || Object3D
            QString de = QString(depth->text());
            if(!(de.trimmed().isEmpty())) //Object3D
                emit updateObj3DD(selectedItem);
            else
                emit updateObj2DD(selectedItem); //Object2D
        }
        else
            emit updateObj1DD(selectedItem); //object1D

    }
}

void SelectDetails::updateColorD(QListWidgetItem *i)
{
    selectedItem = i;
    length->setText(tr(""));
    height->setText(tr(""));
    depth->setText(tr(""));
    ris->setText(tr(""));
    length->setDisabled(true);
    height->setDisabled(true);
    depth->setDisabled(true);
    ris->setDisabled(true);
    color->setDisabled(false);
    boxMisura->setDisabled(true);
    colorZ->show();

    index = (i->text().toInt());
    std::string s = (log->getRGBHex(index))->getColor();
    color->setText("#"+QString::fromStdString(s));
    RGBHex c = RGBHex(s);
    colorZ->setRed(c.getRint());
    colorZ->setGreen(c.getGint());
    colorZ->setBlue(c.getBint());

    //aggiorno
    Grid->update();
    repaint();

}

void SelectDetails::updateObj1DD(QListWidgetItem *i)
{
    selectedItem = i;
    length->setText(tr(""));
    height->setText(tr(""));
    depth->setText(tr(""));
    ris->setText(tr(""));
    length->setDisabled(false);
    height->setDisabled(true);
    depth->setDisabled(true);
    ris->setDisabled(false);
    color->setDisabled(false);
    boxMisura->setDisabled(false);
    colorZ->show();

    index = (i->text().toInt());
    Object_1D* o = log->getObj1D(index);
    log->setSelezione(o);
    Status s = o->getStatus();



}

void SelectDetails::updateObj2DD(QListWidgetItem *i)
{

}

void SelectDetails::updateObj3DD(QListWidgetItem *i)
{

}

#include "select.h"

Select::Select(BusinessLogic *l, QWidget *parent) : QWidget(parent), log(l)
{
    struttura = new QGridLayout(this);
    Object1DSelect = new QListWidget();
    Object2DSelect = new QListWidget();
    Object3DSelect = new QListWidget();
    ColSelected = new QListWidget();
    QLabel* s1D = new QLabel(tr("Object1D"));
    QLabel* s2D = new QLabel(tr("Object2D"));
    QLabel* s3D = new QLabel(tr("Object3D"));
    QLabel* sc = new QLabel(tr("Color"));

    //select Object1D
    for(int i=0; log->getVectorSize(0); i++)
        Object1DSelect->addItem(QString::number(i));
    //select Object2D
    for(int i=0; log->getVectorSize(1); i++)
        Object2DSelect->addItem(QString::number(i));
    //select Object3D
    for(int i=0; log->getVectorSize(2); i++)
        Object3DSelect->addItem(QString::number(i));
    //select Color
    for(int i=0; log->getVectorSize(3); i++)
        ColSelected->addItem(QString::number(i));

    Object1DSelect->setFixedSize(200, 300);
    Object2DSelect->setFixedSize(200, 300);
    Object3DSelect->setFixedSize(200, 300);
    ColSelected->setFixedSize(200, 300);

    struttura->addWidget(s1D,0,0);
    struttura->addWidget(s2D,0,1);
    struttura->addWidget(s3D,0,2);
    struttura->addWidget(sc,0,3);

    struttura->addWidget(Object1DSelect,1,0);
    struttura->addWidget(Object2DSelect,1,1);
    struttura->addWidget(Object3DSelect,1,2);
    struttura->addWidget(ColSelected,1,3);

    //costruisco details
    Box = new SelectDetails(log);
    struttura->addWidget(Box, 0, 4, 2, 1);

    //Connect (quando viene selezionato o cliccato un elemento va ggiornato details in base all'elemento in cui sono)
    connect(Object1DSelect, SIGNAL(itemActivated(QListWidgetItem*)), Box, SLOT(updateObj1DD(QListWidgetItem*)));
    connect(Object1DSelect, SIGNAL(itemClicked(QListWidgetItem*)), Box, SLOT(updateObj1DD(QListWidgetItem*)));
    connect(Object2DSelect, SIGNAL(itemActivated(QListWidgetItem*)), Box, SLOT(updateObj2DD(QListWidgetItem*)));
    connect(Object2DSelect, SIGNAL(itemClicked(QListWidgetItem*)), Box, SLOT(updateObj2DD(QListWidgetItem*)));
    connect(Object3DSelect, SIGNAL(itemActivated(QListWidgetItem*)), Box, SLOT(updateObj3DD(QListWidgetItem*)));
    connect(Object3DSelect, SIGNAL(itemClicked(QListWidgetItem*)), Box, SLOT(updateObj3DD(QListWidgetItem*)));
    connect(ColSelected, SIGNAL(itemActivated(QListWidgetItem*)), Box, SLOT(updateColorD(QListWidgetItem*)));
    connect(ColSelected, SIGNAL(itemClicked(QListWidgetItem*)), Box, SLOT(updateColorD(QListWidgetItem*)));




}

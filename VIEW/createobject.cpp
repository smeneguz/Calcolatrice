#include "createobject.h"

CreateObject::CreateObject(BusinessLogic* l,QWidget *parent) : QWidget(parent)
{
        struttura = new QGridLayout(this);
        NewObject1D* n1 = new NewObject1D(l);
        NewObject2D* n2 = new NewObject2D(l);
        NewObject3D* n3 = new NewObject3D(l);
        CreateColor* nc = new CreateColor(l);


        struttura->addWidget(n1, 0, 1);
        struttura->addWidget(n2, 0, 2);
        struttura->addWidget(n3, 0, 3);
        struttura->addWidget(nc, 0, 4);

        connect(n1, SIGNAL(Object1DAdded()), this, SLOT(addObject1D()));
        connect(n2, SIGNAL(Object2DAdded()), this, SLOT(addObject2D()));
        connect(n3, SIGNAL(Object3DAdded()), this, SLOT(addObject3D()));
        connect(nc, SIGNAL(colorAdded()), this, SLOT(addColor()));

}

void CreateObject::addObject1D()
{
    emit itemAdded();

}

void CreateObject::addObject2D()
{
    emit itemAdded();

}

void CreateObject::addObject3D()
{
    emit itemAdded();

}

void CreateObject::addColor()
{
    emit itemAdded();

}

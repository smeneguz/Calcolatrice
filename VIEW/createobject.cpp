#include "createobject.h"

CreateObject::CreateObject(BusinessLogic* l,QWidget *parent) : QWidget(parent)
{

    log = l;
        struttura = new QGridLayout(this);
        n1 = new NewObject1D(l);
        n2 = new NewObject2D(l);
        n3 = new NewObject3D(l);
        nc = new CreateColor(l);

        /*

        struttura->addWidget(n1, 0, 1);
        struttura->addWidget(n2, 0, 2);
        struttura->addWidget(n3, 0, 3);
        struttura->addWidget(nc, 0, 4);
*/
        connect(n1, SIGNAL(Object1DAdded()), this, SLOT(addObject1D()));
        connect(n2, SIGNAL(Object2DAdded()), this, SLOT(addObject2D()));
        connect(n3, SIGNAL(Object3DAdded()), this, SLOT(addObject3D()));
        connect(nc, SIGNAL(colorAdded()), this, SLOT(addColor()));




        // Configurazioni della finestra;
        //setWindowTitle(tr("Kalc"));
        //setWindowIcon(QIcon(":/img/kalk.png"));
        //setGeometry(200,150,1000,500);

        //MENU
        QMenuBar* menuBar = new QMenuBar();
        Create = new QMenu(tr("Create"), this);
        menuBar->addMenu(Create);
        this->layout()->setMenuBar(menuBar);
        //struttura->menuBar()->addMenu(Create);S

        //Create OBJ1D
        Add_Obj1D = new QAction(QIcon(":/img/1D.png"), tr("Create new Object1D"), this);
        Create->addAction(Add_Obj1D);
        //connect(Add_Obj1D, SIGNAL)
        connect(Add_Obj1D, SIGNAL(triggered(bool)), this, SLOT(addObject1Dprova()));
        //connect(n1, SIGNAL(Object1DAdded()), this, SLOT(addObject1D()));

        //Create OBJ2D
        Add_Obj2D = new QAction(QIcon(":/img/2D.png"), tr("Create new Object2D"), this);
        Create->addAction(Add_Obj2D);
                connect(Add_Obj2D, SIGNAL(triggered(bool)), this, SLOT(addObject2Dprova()));
       // connect(n2, SIGNAL(Object2DAdded()), this, SLOT(addObject2D()));

        //Create OBJ3D
        Add_Obj3D = new QAction(QIcon(":/img/3D.png"), tr("Create new Object3D"), this);
        Create->addAction(Add_Obj3D);
        connect(Add_Obj3D, SIGNAL(triggered(bool)), this, SLOT(addObject3Dprova()));
        //connect(n3, SIGNAL(Object3DAdded()), this, SLOT(addObject3D()));

        //Create Color
        Add_Color = new QAction(QIcon(":/img/color.png"), tr("Create new Color"), this);
        Create->addAction(Add_Color);
        connect(Add_Color, SIGNAL(triggered(bool)), this, SLOT(addColorprova()));
       // connect(nc, SIGNAL(colorAdded()), this, SLOT(addColor()));

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

void CreateObject::addObject1Dprova()
{
    n1->show();

}

void CreateObject::addObject2Dprova()
{
    n2->show();
}

void CreateObject::addObject3Dprova()
{
    n3->show();
}

void CreateObject::addColorprova()
{
    nc->show();
}


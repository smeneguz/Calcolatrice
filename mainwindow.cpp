#include "mainwindow.h"




MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {





    BusinessLogic* bu = new BusinessLogic();
    Contenitore* cc = new Contenitore(bu);
    setCentralWidget(cc);



    //da mettere in tutte le classi qdialog di creazione
    //connect(a1, SIGNAL(itemAdded()), this, SLOT(addItem()));

    //n2 = new NewObject2D(bu);
    //struttura->addWidget(n2);
    //all->setLayout(struttura);




    //setCentralWidget(t);

    //this->setCentralWidget(all);


    //n3 = new NewObject3D(bu);
    //nc = new CreateColor(bu);

    //questi mi posizionano i creatori di oggetti in homepage ma non voglio
    //struttura->addWidget(n1,0,0);
    //struttura->addWidget(n2,0,1);
    //struttura->addWidget(n3,0,2);
    //struttura->addWidget(nc,0,3);

    //this->setLayout(struttura);
    //this->layout();


/*

    // Configurazioni della finestra;
    setWindowTitle(tr("Kalc"));
    setWindowIcon(QIcon(":/img/kalk.png"));
    setGeometry(200,150,1000,500);

    //MENU
    Create = new QMenu(tr("Create"), this);
    menuBar()->addMenu(Create);

    //Create OBJ1D
    Add_Obj1D = new QAction(QIcon(":/img/1D.png"), tr("Create new Object1D"), this);
    Create->addAction(Add_Obj1D);
    //connect(Add_Obj1D, SIGNAL)
    connect(Add_Obj1D, SIGNAL(triggered(bool)), this, SLOT(addObject1D()));
    //connect(n1, SIGNAL(Object1DAdded()), this, SLOT(addObject1D()));

    //Create OBJ2D
    Add_Obj2D = new QAction(QIcon(":/img/2D.png"), tr("Create new Object2D"), this);
    Create->addAction(Add_Obj2D);
   // connect(n2, SIGNAL(Object2DAdded()), this, SLOT(addObject2D()));

    //Create OBJ3D
    Add_Obj3D = new QAction(QIcon(":/img/3D.png"), tr("Create new Object3D"), this);
    Create->addAction(Add_Obj3D);
    //connect(n3, SIGNAL(Object3DAdded()), this, SLOT(addObject3D()));

    //Create Color
    Add_Color = new QAction(QIcon(":/img/color.png"), tr("Create new Color"), this);
    Create->addAction(Add_Color);
   // connect(nc, SIGNAL(colorAdded()), this, SLOT(addColor()));

    //Menu Secondario
    //statusBar();

    //connect(this, SIGNAL(itemAdded()), t , SLOT(addItem()));



    //t->show();
    //Connect quando bottoni vengono premuti si deve creare la finestrab qdialog appropriata per 1D ecc..
    //connect(Add_Obj1D, SIGNAL(triggered(bool)), this, SLOT(prova()));


    /////////////////////////////////////////PROVA DIALOG //////////////

    //QDialog* prova = new QDialog();
    //prova->setLayout(n1->getStruttura());
    //prova->show();
    //connect(Add_Obj1D, SIGNAL(triggered(bool)), n1, SLOT(displaycreate(bu)) );

*/

}

/*
void MainWindow::addObject1D()
{
    emit itemAdded();
    //n1 = new NewObject1D(bu);
    //n1->show();
    //emit itemAdded();

}

void MainWindow::addObject2D()
{
    emit itemAdded();
}

void MainWindow::addObject3D()
{
    emit itemAdded();
}

void MainWindow::addColor()
{
    emit itemAdded();
}

*/


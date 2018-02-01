#include "mainwindow.h"




MainWindow::MainWindow(MainWindow *parent) : QMainWindow(parent) {





    bu = new BusinessLogic();
    Contenitore* cc = new Contenitore(bu);
    setCentralWidget(cc);

    //this->setStyleSheet("background-color: white;");



    //da mettere in tutte le classi qdialog di creazione
    //connect(a1, SIGNAL(itemAdded()), this, SLOT(addItem()));

    //n2 = new NewObject2D(bu);
    //struttura->addWidget(n2);
    //all->setLayout(struttura);




    //setCentralWidget(t);

    //this->setCentralWidget(all);



}





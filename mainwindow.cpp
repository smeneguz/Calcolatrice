#include "mainwindow.h"




MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {



    /* Configurazioni della finestra; */
    setWindowTitle(tr("Kalk"));
    setWindowIcon(QIcon(":/images/logo.png"));
    setGeometry(200,150,1000,500);




    BusinessLogic* bu = new BusinessLogic();
    Table* t =new Table(bu);






    t->show();






}

void MainWindow::addObject1D()
{

}

void MainWindow::addObject2D()
{

}

void MainWindow::addObject3D()
{

}

void MainWindow::addColor()
{

}


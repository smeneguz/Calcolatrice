#include "mainwindow.h"
#include <QIcon>



MainWindow::MainWindow(MainWindow *parent) : QMainWindow(parent) {




    bu = new BusinessLogic();
    Contenitore* cc = new Contenitore(bu);
    setCentralWidget(cc);

    //this->setStyleSheet("background-color: white;");


}





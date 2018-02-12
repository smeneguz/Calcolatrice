#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <typeinfo>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow m;

    m.setWindowTitle("Space Kalk");
    m.setWindowIcon(QIcon(":/img/icon.png"));

    m.show();


    return a.exec();
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QApplication>
#include <QCloseEvent>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QFile>

#include <QMainWindow>

#include "./VIEW/contenitore.h"
#include "./MODEL/businesslogic.h"

#include <QGroupBox>
#include <QScrollArea>




class MainWindow : public QMainWindow {
    Q_OBJECT

private:

    QMenu* Create;
        QAction* Add_Obj1D;
        QAction* Add_Obj2D;
        QAction* Add_Obj3D;
        QAction* Add_Color;
        BusinessLogic* bu;




public:
    MainWindow(MainWindow *parent = 0);




public slots:
   // void addObject1D();

};








//private slots:
   //void store();
   //void chiudi();
   //void mostraTutto();
   //void nascondi();
   //void aggiungiDato();
   //void aggiungiNuovo();






#endif // MAINWINDOW_H

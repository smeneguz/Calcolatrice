#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QApplication>
#include <QCloseEvent>

#include <QMenu>
#include <QToolBar>
#include <QFile>

#include <QMainWindow>
#include <QMenuBar>
#include "./VIEW/table.h"
#include "./VIEW/calculate.h"
#include "./MODEL/businesslogic.h"
#include "./VIEW/newobject1d.h"
#include "./VIEW/newobject2d.h"
#include "./VIEW/newobject3d.h"
#include "./VIEW/createcolor.h"
#include <QGroupBox>



class MainWindow : public QMainWindow {
    Q_OBJECT

private:

    QMenu* Create;
        QAction* Add_Obj1D;
        QAction* Add_Obj2D;
        QAction* Add_Obj3D;
        QAction* Add_Color;

    QGridLayout* struttura;



public:
    MainWindow(QWidget *parent = 0);

signals:
    void itemAdded();

public slots:
    void addObject1D();
    void addObject2D();
    void addObject3D();
    void addColor();

};








//private slots:
   //void store();
   //void chiudi();
   //void mostraTutto();
   //void nascondi();
   //void aggiungiDato();
   //void aggiungiNuovo();






#endif // MAINWINDOW_H

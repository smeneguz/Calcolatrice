#ifndef CREATEOBJECT_H
#define CREATEOBJECT_H
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include "./MODEL/businesslogic.h"
#include "./VIEW/newobject1d.h"
#include "./VIEW/newobject2d.h"
#include "./VIEW/newobject3d.h"
#include "./VIEW/createcolor.h"

#include <QApplication>
#include <QCloseEvent>
#include <QMenuBar>
#include <QMenu>
#include <QToolBar>
#include <QFile>
//#include <mainwindow.h>
//area creazione oggetti
class CreateObject : public QWidget {
    Q_OBJECT
private:
    QGridLayout* struttura;
    QMenu* Create;
        QAction* Add_Obj1D;
        QAction* Add_Obj2D;
        QAction* Add_Obj3D;
        QAction* Add_Color;
        BusinessLogic* log;


        NewObject1D* n1;
        NewObject2D* n2;
        NewObject3D* n3;
        CreateColor* nc;
public:
    CreateObject(BusinessLogic* l, QWidget *parent = 0);

signals:
    void itemAdded();
public slots:
    void addObject1D();
    void addObject2D();
    void addObject3D();
    void addColor();
    void addObject1Dprova ();
    void addObject2Dprova ();
    void addObject3Dprova ();
    void addColorprova ();
};

#endif // CREATEOBJECT_H

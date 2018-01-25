#ifndef CONTENITORE_H
#define CONTENITORE_H
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
#include "./VIEW/createobject.h"
#include <QGroupBox>

class Contenitore : public QWidget {
    Q_OBJECT
private:

    QGridLayout* struttura;
    BusinessLogic* log;

    //oggetti new
    //NewObject1D* n1;
    //NewObject2D* n2;
    //NewObject3D* n3;
    //CreateColor* nc;

    //area sel
    Table* se;
    //area calcolo
    Calculate* c;
    //creazione area
    CreateObject* crea;
public:
    Contenitore(BusinessLogic* l, QWidget *parent = 0);

signals:
    void refreshItemList();

public slots:
    void addItem();
};

#endif // CONTENITORE_H

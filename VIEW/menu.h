#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "../MODEL/businesslogic.h"
#include "newobject1d.h"
#include "newobject2d.h"
#include "newobject3d.h"
#include "createcolor.h"

class Menu : public QMainWindow {
    Q_OBJECT
private:

    QMenu* Create;
        QAction* Add_Obj1D;
        QAction* Add_Obj2D;
        QAction* Add_Obj3D;
        QAction* Add_Color;
        QGridLayout* struttura;

public:
    Menu(BusinessLogic* l, QWidget *parent = 0);

signals:
    void itemAdded();

public slots:
    void addObject1D();
    void addObject2D();
    void addObject3D();
    void addColor();

};

#endif // MENU_H

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

//area creazione oggetti
class CreateObject : public QWidget {
    Q_OBJECT
private:
    QGridLayout* struttura;
public:
    CreateObject(BusinessLogic* l, QWidget *parent = 0);

signals:
    void itemAdded();
public slots:
    void addObject1D();
    void addObject2D();
    void addObject3D();
    void addColor();
};

#endif // CREATEOBJECT_H

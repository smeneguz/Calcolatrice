#ifndef FINESTRAOBJECT1D_H
#define FINESTRAOBJECT1D_H
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include "./MODEL/businesslogic.h"
#include "./VIEW/newobject1d.h"
#include <QObject>

class FinestraObject1D : public QWidget
{
    Q_OBJECT
public:
    FinestraObject1D(BusinessLogic* l, QWidget *parent = 0);

signals:
    void itemAdded();
public slots:
    //void addObject1D();
};

#endif // FINESTRAOBJECT1D_H

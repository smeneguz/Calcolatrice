#ifndef SELECT_H
#define SELECT_H
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QWidget>
#include "../MODEL/businesslogic.h"
#include "selectdetails.h"

//Select Zone
class Select : public QWidget {
    Q_OBJECT
private:
     QListWidget* Object1DSelect;
     QListWidget* Object2DSelect;
     QListWidget* Object3DSelect;
     QListWidget* ColSelected;
     SelectDetails* Box;
     QGridLayout* struttura;
     BusinessLogic* log;
public:
    Select(BusinessLogic* l, QWidget *parent = 0);

};

#endif // SELECT_H

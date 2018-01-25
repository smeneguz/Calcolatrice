#ifndef TABLE_H
#define TABLE_H
#include <QGridLayout>
#include <QWidget>

#include <QLabel>
#include <QPushButton>
#include <QListWidget>

#include "../MODEL/businesslogic.h"
#include "selectdetails.h"
//#include "select.h" inutilizzata
//zona selezione

class Table : public QWidget {
    Q_OBJECT
private:
    //BusinessLogic* log;
    //QGridLayout* table;
    QListWidget* Object1DSelect;
    QListWidget* Object2DSelect;
    QListWidget* Object3DSelect;
    QListWidget* ColSelected;
    SelectDetails* Box;
    QGridLayout* struttura;
    BusinessLogic* log;
public:
    Table(BusinessLogic *l, QWidget *parent = 0);



};

#endif // TABLE_H

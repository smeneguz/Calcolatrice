#ifndef TABLE_H
#define TABLE_H
#include <QGridLayout>
#include <QWidget>
#include "select.h"

class Table : public QWidget {
    Q_OBJECT
private:
    BusinessLogic* log;
    QGridLayout* table;
    Select* sel;
public:
    Table(BusinessLogic *l, QWidget *parent = 0);

signals:
    void refresh();

public slots:
    void addItem();
};

#endif // TABLE_H

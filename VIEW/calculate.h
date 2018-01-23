#ifndef CALCULATE_H
#define CALCULATE_H
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QWidget>
#include "operatori.h"
#include "../MODEL/businesslogic.h"

class Calculate : public QWidget {
    Q_OBJECT
private:
    QLineEdit* firsto;
    QLineEdit* secondo;
    QLineEdit* risultato;
    BusinessLogic* log;
    QGridLayout* struttura;
    QPushButton* add1o;
    QPushButton* add2o;
    QPushButton* uguale;
    QPushButton* save;
    Operatori* op;



public:
    Calculate(BusinessLogic* l, QWidget *parent = 0);

signals:
    void itemAdded();

public slots:
    void setOperator();
    void addOp1();
    void addOp2();
    void execute();
    void clear();
    void saveResult();
};

#endif // CALCULATE_H

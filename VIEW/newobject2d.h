#ifndef NEWOBJECT2D_H
#define NEWOBJECT2D_H

#include "../MODEL/businesslogic.h"
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QMessageBox>
#include <QString>

class NewObject2D : public QDialog {
    Q_OBJECT
private:
    BusinessLogic* log;
    QGroupBox*  newLineBox;
    QGridLayout* gridBox ;
    QGridLayout* struttura;
    QGroupBox* boxMisura; //unità di misura
    QGridLayout* gridMisura;
    QLineEdit* risoluzione;
    QLineEdit* length;
    QLineEdit* height; //aggiunta rispetto object1d
    QPushButton* create;
    int misura; // 0=pixel 1=cm 2=inch
public:
    NewObject2D(BusinessLogic *l, QDialog *parent = 0);

signals:
    void Object2DAdded();

public slots:
    void saveObject2D();
    void setPx();
    void setCm();
    void setInch();
};

#endif // NEWOBJECT2D_H

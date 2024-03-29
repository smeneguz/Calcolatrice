#ifndef NEWOBJECT1D_H
#define NEWOBJECT1D_H
#include <QDialog>

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

class NewObject1D : public QDialog {
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
    QPushButton* create;
    int misura; // 0=pixel 1=cm 2=inch
public:
    NewObject1D(BusinessLogic *l, QDialog *parent = 0);


signals:   
    void Object1DAdded();

public slots:
    void saveObject1D();
    void setPx();
    void setCm();
    void setInch();
};

#endif // NEWOBJECT1D_H

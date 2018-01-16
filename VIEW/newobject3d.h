#ifndef NEWOBJECT3D_H
#define NEWOBJECT3D_H
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


class NewObject3D : public QWidget {
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
    QLineEdit* depth;//aggiunta rispetto object2d
    QPushButton* create;
    int misura; // 0=pixel 1=cm 2=inch
public:
    NewObject3D(BusinessLogic* l, QWidget *parent = 0);

signals:
    void Object3DAdded();

public slots:
    void saveObject3D();
    void setPx();
    void setCm();
    void setInch();
};

#endif // NEWOBJECT3D_H

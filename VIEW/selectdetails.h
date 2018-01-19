#ifndef SELECTDETAILS_H
#define SELECTDETAILS_H
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QImage>
#include <QRadioButton>
#include <QListWidgetItem>
#include <string>
#include <QWidget>
#include "../MODEL/businesslogic.h"
#include "colorzone.h"

class SelectDetails : public QWidget {
    Q_OBJECT
private:
    QLineEdit* length;
    QLineEdit* height;
    QLineEdit* depth;
    QLineEdit* ris;
    QLineEdit* color;
    BusinessLogic* log;
    QGridLayout* struttura;
    QGroupBox* Box;
    QGridLayout* Grid;
    ColorZone* colorZ;
    QListWidgetItem* selectedItem;
    QGroupBox*  boxMisura;
    int index;
    int misura;

public:
    SelectDetails(BusinessLogic* l, QWidget *parent = 0);

signals:
    //unici cambiamenti poddibili in questa sezione sono per misura
    void changeMeasureObj1D(QListWidgetItem* i);
    void changeMeasureObj2D(QListWidgetItem* i);
    void changeMeasureObj3D(QListWidgetItem* i);

public slots:
    void setPx();
    void setCm();
    void setInch();
    void updateColorD(QListWidgetItem* i);
    void updateObj1DD(QListWidgetItem* i);
    void updateObj2DD(QListWidgetItem* i);
    void updateObj3DD(QListWidgetItem* i);

};

#endif // SELECTDETAILS_H

#ifndef CREATEOBJECT1DDIALOG_H
#define CREATEOBJECT1DDIALOG_H
#include <QDialog>
#include <QLineEdit>
#include <QString>
#include "../MODEL/businesslogic.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QMessageBox>

class CreateObject1DDialog : public QDialog {
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

    //nuovi campi privati per layout
    QVBoxLayout* main;
    QVBoxLayout* dati;
    QPushButton* annulla;
public:
    CreateObject1DDialog(BusinessLogic* l, QWidget* parent=0);
public slots:
    void saveObject1D();
    void setPx();
    void setCm();
    void setInch();
signals:
    void Object1DAdded();
};

#endif // CREATEOBJECT1DDIALOG_H

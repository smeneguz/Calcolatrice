#include "createobject1ddialog.h"

CreateObject1DDialog::CreateObject1DDialog(BusinessLogic *l, QWidget *parent) : QDialog(parent), log(l)
{
    this->setWindowTitle("Add new Object1D");
    QDialog::reject();
    this->setModal(true);
    this->resize(500,300);

    main = new QVBoxLayout;
    newLineBox = new QGroupBox(tr("enter the data"));
    dati = new QVBoxLayout;
}

void CreateObject1DDialog::saveObject1D()
{

}

void CreateObject1DDialog::setPx()
{

}

void CreateObject1DDialog::setCm()
{

}

void CreateObject1DDialog::setInch()
{

}

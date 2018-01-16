#include "toolbar.h"

Toolbar::Toolbar(BusinessLogic *l, QWidget *parent): QTableWidget(parent), log(l)
{
    struttura = new QGridLayout(this);
    selectObj1D = new QListWidget();
    selectObj2D = new QListWidget();
    selectCol = new QListWidget();

    /* Configurazione generali della tabella */
    this->setRowCount(0);
    this->setColumnCount(3);

}

void Toolbar::aggiungi(Object *p)
{

}

void Toolbar::rimuovi()
{

}

void Toolbar::rimuovi_tutte()
{

}

void Toolbar::showAll()
{

}

void Toolbar::hideAll()
{

}

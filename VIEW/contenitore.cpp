#include "contenitore.h"

Contenitore::Contenitore(BusinessLogic *l, QWidget *parent) : QWidget(parent)
{

    log = l;

    struttura = new QGridLayout(this);

    //parte di calcolo
    c = new Calculate(log);
    struttura->addWidget(c);
    //parte di contenitori oggetti e visione dettagli
    se = new Table(log);
    struttura->addWidget(se);
    //creazione ogg
    crea = new CreateObject(log);
    struttura->addWidget(crea);


    //
    connect(c, SIGNAL(itemAdded()), this, SLOT(addItem()));
    connect(crea, SIGNAL(itemAdded()), this, SLOT(addItem()));


}

void Contenitore::addItem()
{
    //area sel va cambiata e rifatta
    Table* a = new Table(log);
    struttura->addWidget(a, 1, 0);
    delete se;
    se = new Table(log);
    struttura->removeWidget(a);
    struttura->addWidget(se, 1, 0);
    delete a;
    a = 0;
    //emit refreshItemList();
}

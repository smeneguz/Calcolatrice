#include "table.h"

Table::Table(BusinessLogic* l, QWidget *parent) : QWidget(parent), log(l)
{
    table = new QGridLayout(this);
    sel = new Select(log);
    table->addWidget(sel, 0, 0);

    //fare connect

}

void Table::addItem()
{
    Select* a = new Select(log);
    table->addWidget(a, 0, 0);
    delete sel;
    sel = new Select(log);
    table->removeWidget(a);
    table->addWidget(sel, 0, 0);
    delete a;
}

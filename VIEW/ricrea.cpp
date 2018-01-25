#include "ricrea.h"

Ricrea::Ricrea(BusinessLogic *l, QWidget *parent) : QWidget(parent)
{
    MainWindow* mm = new MainWindow(l);
    mm->show();

}

#ifndef TOOLBAR_H
#define TOOLBAR_H
#include "../MODEL/businesslogic.h"
#include <QTableWidget>
class Toolbar : public QTableWidget {
public:
    Toolbar();

public slots:
   void aggiungi(Object* p=new Object_1D());
   void rimuovi();
   void rimuovi_tutte();
   void showAll();
   void hideAll();
};

#endif // TOOLBAR_H

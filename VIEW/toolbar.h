#ifndef TOOLBAR_H
#define TOOLBAR_H
#include "../MODEL/businesslogic.h"
#include <QTableWidget>
#include <QGridLayout>
#include <QStringList>
#include <QListWidget>
#include <QMessageBox>
#include <QWidget>
class Toolbar : public QTableWidget {
public:
    Toolbar(BusinessLogic* l,  QWidget* parent=0 );
private:
    BusinessLogic * log;
    QGridLayout* struttura;
    QListWidget* selectObj1D;
    QListWidget* selectObj2D;
    //QListWidget* selectObj3D;
    QListWidget* selectCol;




public slots:
   void aggiungi(Object* p=new Object());
   void rimuovi();
   void rimuovi_tutte();
   void showAll();
   void hideAll();
};

#endif // TOOLBAR_H

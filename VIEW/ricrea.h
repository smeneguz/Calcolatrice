#ifndef RICREA_H
#define RICREA_H
#include "../mainwindow.h"
#include "../MODEL/businesslogic.h"

#include <QWidget>

class Ricrea : public QWidget {
    Q_OBJECT
public:
    Ricrea(BusinessLogic* l, QWidget *parent = 0);

signals:

public slots:
};

#endif // RICREA_H

#ifndef PROVA_H
#define PROVA_H

#include <QWidget>

#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QMessageBox>
#include <QString>

class Prova : public QWidget{
    Q_OBJECT
    //////////PROVA
private:
    QGridLayout *acc;
    QGroupBox *bbb ;
public:
    Prova(QWidget *parent = 0);
};

#endif // PROVA_H

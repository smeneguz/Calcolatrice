#ifndef OPERATORI_H
#define OPERATORI_H
#include <QGridLayout>
#include <QPushButton>
#include <QRadioButton>
#include <QGroupBox>
#include <QWidget>

class Operatori : public QWidget {
    Q_OBJECT
private:
    int selezione;
    QGridLayout* struttura;
    QGroupBox* createBox() const;
public:
    Operatori(QWidget *parent = 0);
    int getSelectedOperator() const; // 0=somma , 1=sottrazione , 2=moltiplicazione , 3=divisione

signals:
    void operatorChanged();

public slots:
    void selectSomma();
    void selectSottrazione();
    void selectMoltiplicazione();
    void selectDivisione();
};

#endif // OPERATORI_H

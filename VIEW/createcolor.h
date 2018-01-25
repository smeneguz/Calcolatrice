#ifndef COLOR_H
#define COLOR_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QSlider>
#include <QTextEdit>
#include <QColor>
#include <QString>
#include <QApplication>
#include "colorrange.h"
#include "colorzone.h"
#include "../MODEL/businesslogic.h"

class CreateColor : public QWidget {
    Q_OBJECT
private:
    ColorZone* colorZone;
    ColorRange* Rslider;
    ColorRange* Gslider;
    ColorRange* Bslider;
    QLineEdit* colhex;
    QGridLayout* struttura;
    QPushButton* create;
    BusinessLogic* log;
    RGBHex col;
public:
    CreateColor(BusinessLogic* l, QWidget *parent = 0);

signals:
    void colorAdded();


public slots:
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);
    void saveColor();
};

#endif // COLOR_H

#ifndef COLORRANGE_H
#define COLORRANGE_H

#include <QWidget>
#include "../MODEL/rgbhex.h"
#include <QSlider>
#include <QLineEdit>
#include <string>
#include <QGridLayout>


class ColorRange : public QWidget {
    Q_OBJECT
private:
    QSlider* slider; //slider color
    QLineEdit* intVal; //set digitando color

public:
    ColorRange(QWidget *parent = 0);
    int value() const; //valore col
    void setRange(int min, int max);

signals:
    void valueChanged (int c);

public slots:
    void changeRed(QString s);
    void changeGreen(QString s);
    void changeBlue(QString s);
    void setValue(QString c);
    void changeIntVal(int c);

};

#endif // COLORRANGE_H

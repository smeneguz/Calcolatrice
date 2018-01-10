#ifndef COLORZONE_H
#define COLORZONE_H

#include <QWidget>
#include <QPainter>
#include "../MODEL/rgbhex.h"

class ColorZone : public QWidget {
    Q_OBJECT
private:
    int red;
    int green;
    int blue;
public:
    ColorZone(QWidget *parent = 0);
    int getRed() const;
    int getGreen() const;
    int getBlue() const;

signals:
    void colorChanged(QString s);
private:
    void paintEvent(QPaintEvent* );

public slots:
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);
};

#endif // COLORZONE_H

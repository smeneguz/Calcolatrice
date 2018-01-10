#include "colorzone.h"

ColorZone::ColorZone(QWidget *parent) : QWidget(parent)
{
    red = 0;
    green = 0;
    blue = 0;
    setPalette(QPalette(QColor(red,green,blue)));
    ///
    /// \brief setAutoFillBackground Questa proprietà determina se lo sfondo del widget viene riempito automaticamente.
    /// Se abilitata, questa proprietà farà sì che Qt riempia lo sfondo del widget prima di richiamare l'evento paint. Il colore utilizzato è definito dal ruolo del colore QPalette :: Finestra dalla tavolozza del widget.
    ///
    setAutoFillBackground(true);
}

int ColorZone::getRed() const
{
    return red;
}

int ColorZone::getGreen() const
{
    return green;
}

int ColorZone::getBlue() const
{
    return blue;
}

void ColorZone::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //painter.drawText(10,10,QString::number(red)+":"+QString::number(green)+":"+QString::number(blue));
}

void ColorZone::setRed(int r)
{
    if (r < 0) r = 0;
    if (r > 255) r = 255;
    if (red == r) return;
    red = r;
    update();
    setPalette(QPalette(QColor(red,green,blue)));
    setAutoFillBackground(true);
    RGBHex c = RGBHex(red,green,blue);
    QString s = QString::fromStdString("#"+c.getColor());
    emit colorChanged(s);
}

void ColorZone::setGreen(int g)
{
    if (g < 0) g = 0;
    if (g > 255) g = 255;
    if (green == g) return;
    green = g;
    update();
    setPalette(QPalette(QColor(red,green,blue)));
    setAutoFillBackground(true);
    RGBHex c = RGBHex(red,green,blue);
    QString s = QString::fromStdString("#"+c.getColor());
    emit colorChanged(s);
}

void ColorZone::setBlue(int b)
{
    if (b < 0) b = 0;
    if (b > 255) b = 255;
    if (blue == b) return;
    blue = b;
    update();
    setPalette(QPalette(QColor(red,green,blue)));
    setAutoFillBackground(true);
    RGBHex c = RGBHex(red,green,blue);
    QString s = QString::fromStdString("#"+c.getColor());
    emit colorChanged(s);
}

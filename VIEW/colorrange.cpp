#include "colorrange.h"

ColorRange::ColorRange(QWidget *parent) : QWidget(parent)
{
    slider = new QSlider(Qt::Horizontal);
    intVal = new QLineEdit(tr("0"));
    intVal->setFixedWidth(40);
    slider->setRange(0,255);

    //connessione slider -> decimal color change
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(changeIntVal(int)));
    //connessione Line Edit box -> change string color
    connect(intVal, SIGNAL(textChanged(QString)), this, SLOT(setValue(QString)));

    //struttura
    QGridLayout* str = new QGridLayout();
    str->addWidget(slider, 0, 0); //top-left quindi sx
    str->addWidget(intVal, 0, 1); //alla destra dello slider
    setLayout(str);
    setFocusProxy(slider);

}

int ColorRange::value() const
{
    return slider->value();
}

void ColorRange::setRange(int min, int max)
{
    if (min < 0 || max > 255 || min > max) {
        qWarning("attention, the values ​​must be between 0..255 and first value must be lower than the second");
        return;
    }
    //valori ok setto il range
    slider->setRange(min, max);
}

void ColorRange::changeRed(QString s)
{
    RGBHex r = RGBHex(s.toStdString());
    slider->setValue(r.getRint());
}

void ColorRange::changeGreen(QString s)
{
    RGBHex g = RGBHex(s.toStdString());
    slider->setValue(g.getGint());
}

void ColorRange::changeBlue(QString s)
{
    RGBHex b = RGBHex(s.toStdString());
    slider->setValue(b.getBint());
}

void ColorRange::setValue(QString c)
{
    slider->setValue(c.toInt());
    emit valueChanged(c.toInt());
}

void ColorRange::changeIntVal(int c)
{
    QString s;
    //arg is a much better solution than sprintf(), because it is type-safe, fully supports Unicode ecc..
    s.append(QString("%1").arg(c));
    intVal->setText(s);
    emit valueChanged(c);
}

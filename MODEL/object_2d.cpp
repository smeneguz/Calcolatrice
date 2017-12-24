#include "object_2d.h"

Object_2d::Object_2d() : Space(), length(1), height(2) {}

Object_2d::Object_2d(int l) : Space(), length(l), height(2) {}

Object_2d::Object_2d(int l, int h) : Space(), length(l), height(h) {}

Object_2d::Object_2d(int l, int h, int risol)  : Space(risol), length(l), height(h) {}

Object_2d::Object_2d(int l, int h, int risol, RGBHex c)  : Space(risol, c), length(l), height(h) {}

int Object_2d::CalcolaSuperficie()
{
    return getLength()*getHeight();
}

int Object_2d::getLength() const
{
    return length;
}

void Object_2d::setLength(int l)
{
    length = l;
}

int Object_2d::getHeight() const
{
    return height;
}

void Object_2d::setHeight(int h)
{
    height = h;
}

Object_2d& Object_2d::operator+(const Space &x)
{
    const Object_2d* a = dynamic_cast<const Object_2d*>(&x);
    if(a)
    {
        int val = this->getLength() + a->getLength();
        int valh = this->getHeight() + a->getHeight();
        this->setLength(val);
        this->setHeight(valh);
        this->setRisoluzione(a->getRisoluzione()); //la somma ritorna semplicemente la risoluzione del parametro passato
        return *this;
    }
    //non fa niente in questo caso se non è del tipo giusto
    throw Ecc_Object2D_somma_ObjectDiverso();
}

Object_2d& Object_2d::operator-(const Space &x)
{

}

Object_2d& Object_2d::operator*(const Space &x)
{

}

Object_2d& Object_2d::operator/(const Space &x)
{

}

Object_2d& Object_2d::operator+(const RGBHex &x)
{
    RGBHex b;
    int val = x.getColorInt() + this->col.getColorInt();
    if (val>16777215) val=16777215;
    b.setColorInt(val);
    this->setColor(b);
    return *this;
}

Object_2d& Object_2d::operator-(const RGBHex &x)
{
    RGBHex b;
    int val = col.getColorInt() - x.getColorInt();
    if(val<0) val=0;
    b.setColorInt(val);
    this->setColor(b);
    return *this;
}

Object_2d& Object_2d::operator*(const RGBHex &x)
{
    this->setColor(x);
    return *this;
}

Object_2d& Object_2d::operator/(const RGBHex &x)
{
    col.getColorInt() == x.getColorInt() ? this->setColor(RGBHex("000000")) : this->setColor(col);
    return *this;
}


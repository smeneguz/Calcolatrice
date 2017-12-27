#include "object_2d.h"
#include "object_1d.h"


Object_2d::Object_2d() : Space(), length(1), height(1) {}

Object_2d::Object_2d(int l) : Space(), length(l), height(1) {}

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
    else
    //non fa niente in questo caso se non è del tipo giusto
    throw Ecc_Object2D_somma_ObjectDiverso();
}

Object_2d& Object_2d::operator-(const Space &x)
{
    const Object_2d* a = dynamic_cast<const Object_2d*>(&x);
    if(a)
    {
        int val = this->getLength() - a->getLength();
        int valh = this->getHeight() - a->getHeight();
        if(val <=0) val = 1;
        if(valh <= 0) valh = 1;
        this->setLength(val);
        this->setHeight(valh);
        this->setRisoluzione(a->getRisoluzione()); //la sottrazione ritorna semplicemente la risoluzione del parametro passato
        return *this;
    }
    else//non fa niente in questo caso se non è del tipo giusto
    throw Ecc_Object2D_sottrazione_ObjectDiverso();
}

Object_2d& Object_2d::operator*(const Space &x)
{
    const Object_2d* a= dynamic_cast<const Object_2d*>(&x);
    if(a)
    {
        int val = this->getLength() * a->getLength();
        int valh = this->getHeight() * a->getHeight();
        this->setLength(val);
        this->setHeight(valh);
        this->setRisoluzione(a->getRisoluzione()); //la moltiplicazione ritorna semplicemente la risoluzione del parametro passato
        return *this;
    }
    const Object_1D* b = dynamic_cast<const Object_1D*>(&x);
    if(b)
    {
        //un oggetto 2 dimensioni moltiplicato per un oggetto a una dimensione dimensione ritorna l'oggetto stesso con la lunghezza moltiplicata
        int val = this->getLength() * b->getLength();
        this->setLength(val);
        return *this;
    }
    throw Ecc_Object2D_moltiplicazione_ObjectDiverso();

}

Object_2d& Object_2d::operator/(const Space &x)
{
    const Object_2d* a= dynamic_cast<const Object_2d*>(&x);
    if(a)
    {
        int val = this->getLength() / a->getLength();
        int valh = this->getHeight() / a->getHeight();
        if(val <=0) val = 1;
        if(valh <= 0) valh = 1;
        this->setLength(val);
        this->setHeight(valh);
        this->setRisoluzione(a->getRisoluzione()); //la divisione ritorna semplicemente la risoluzione del parametro passato
        return *this;
    }
    const Object_1D* b = dynamic_cast<const Object_1D*>(&x);
    if(b)
    {
        //un oggetto 2 dimensioni diviso per un oggetto a una dimensione dimensione ritorna l'oggetto stesso con la lunghezza moltiplicata
        int val = this->getLength() / b->getLength();
        if(val <=0) val = 1;
        this->setLength(val);
        return *this;
    }
    throw Ecc_Object2D_divisione_ObjectDiverso();
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

void Object_2d::setLCm(double l)
{
    length = static_cast<int> (Space::dpi*(l/2.54)); // l/2.54 serve per convertire la lunghezza l da cm a pollici
    if ((Space::dpi*(l/2.54))-length > 0) length++; // Arrotondo per eccesso
}

double Object_2d::getLCm() const
{
    double a = static_cast<double>(length);
    double b = static_cast<double>(Space::dpi);
    return ((a/b)*2.54);
}

void Object_2d::setLInch(double l)
{
    length = static_cast<int> (Space::dpi*l);
    if ((Space::dpi*l)-length > 0) length++; // Arrotondo per eccesso
}

double Object_2d::getLInch() const
{
    double a = static_cast<double>(length);
    double b = static_cast<double>(length);
    return (a/b);
}

void Object_2d::setHCm(double h)
{
    height = static_cast<int> (Space::dpi*(h/2.54)); // l/2.54 serve per convertire la lunghezza l da cm a pollici
    if ((Space::dpi*(h/2.54))-height > 0) height++; // Arrotondo per eccesso
}

double Object_2d::getHCm() const
{
    double a = static_cast<double>(height);
    double b = static_cast<double>(Space::dpi);
    return ((a/b)*2.54);
}

void Object_2d::setHInch(double h)
{
    height = static_cast<int> (Space::dpi*h);
    if ((Space::dpi*h)-height > 0) height++; // Arrotondo per eccesso
}

double Object_2d::getHInch() const
{
    double a = static_cast<double>(height);
    double b = static_cast<double>(height);
    return (a/b);
}


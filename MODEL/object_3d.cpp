#include "object_3d.h"
#include "object_2d.h"
#include "object_1d.h"


Object_3d::Object_3d() : Space(), length(1) ,height(1), depth(1) {}

Object_3d::Object_3d(int l) : Space(), length(l), height(1), depth(1) {}

Object_3d::Object_3d(int l, int h) : Space(), length(l), height(h), depth(1) {}

Object_3d::Object_3d(int l, int h, int d) : Space(), length(l), height(h), depth(d) {}

Object_3d::Object_3d(int l, int h, int d, int risol) : Space(risol), length(l), height(h), depth(d) {}

Object_3d::Object_3d(int l, int h, int d, int risol, RGBHex c) : Space(risol, c), length(l), height(h), depth(d) {}

int Object_3d::CalcolaSuperficie()
{
    return getLength()*getHeight()*getDepth();
}

Status Object_3d::getStatus() const
{
    Status s = Space::getStatus();
    //sistemare lunghezza e altezza e profondità
    s.l = this->getLength();
    s.lCm = this->getLCm();
    s.lInch = this->getLInch();
    s.h = this->getHeight();
    s.hCm = this->getHCm();
    s.hInch = this->getHInch();
    s.d = this->getDepth();
    s.dCm = this->getDCm();
    s.dInch = this->getDInch();
    return s;
}

int Object_3d::getLength() const
{
    return length;
}

void Object_3d::setLength(int l)
{
    length=l;
}

int Object_3d::getHeight() const
{
    return height;
}

void Object_3d::setHeight(int h)
{
    height=h;
}

int Object_3d::getDepth() const
{
    return depth;
}

void Object_3d::setDepth(int d)
{
    depth=d;
}

Object_3d &Object_3d::operator+(const Space &x)
{
    const Object_3d* a= dynamic_cast<const Object_3d*>(&x);
    if(a)
    {
        int val = this->getLength() + a->getLength();
        int valh = this->getHeight() + a->getHeight();
        int vald = this->getDepth() + a->getDepth();
        this->setLength(val);
        this->setHeight(valh);
        this->setDepth(vald);
        this->setRisoluzione(a->getRisoluzione()); //la somma ritorna semplicemente la risoluzione del parametro passato
        return *this;
    }
    else
        //somma con altri tipi di oggetto non ha senso tra oggetti dimensionali
        throw Ecc_Object3D_somma_ObjectDiverso();
}

Object_3d &Object_3d::operator-(const Space &x)
{
    const Object_3d* a= dynamic_cast<const Object_3d*>(&x);
    if(a)
    {
        int val = this->getLength() - a->getLength();
        int valh = this->getHeight() - a->getHeight();
        int vald = this->getDepth() - a->getDepth();
        if(val <=0) val = 1;
        if(valh <= 0) valh = 1;
        if(vald <=0) vald = 1;
        this->setLength(val);
        this->setHeight(valh);
        this->setDepth(vald);
        this->setRisoluzione(a->getRisoluzione()); //la sottrazione ritorna semplicemente la risoluzione del parametro passato
        return *this;
    }
    else
        //somma con altri tipi di oggetto non ha senso tra oggetti dimensionali
        throw Ecc_Object3D_sottrazione_ObjectDiverso();
}

Object_3d &Object_3d::operator*(const Space &x)
{
    const Object_3d* a= dynamic_cast<const Object_3d*>(&x);
    if(a)
    {
        int val = this->getLength() * a->getLength();
        int valh = this->getHeight() * a->getHeight();
        int vald = this->getDepth() * a->getDepth();
        this->setLength(val);
        this->setHeight(valh);
        this->setDepth(vald);
        this->setRisoluzione(a->getRisoluzione()); //la moltiplicazione ritorna semplicemente la risoluzione del parametro passato
        return *this;
    }
    const Object_2d* b = dynamic_cast<const Object_2d*>(&x);
    if(b)
    {
        int val = this->getLength() * b->getLength();
        int valh = this->getHeight() * b->getHeight();
        this->setLength(val);
        this->setHeight(valh);
        this->setRisoluzione(b->getRisoluzione()); //la moltiplicazione ritorna semplicemente la risoluzione del parametro passato
        return *this;
    }
    const Object_1D* c = dynamic_cast<const Object_1D*>(&x);
    if(c)
    {
        //un oggetto 3 dimensioni moltiplicato per un oggetto a una dimensione dimensione ritorna l'oggetto stesso con la lunghezza moltiplicata
        int val = this->getLength() * c->getLength();
        this->setLength(val);
        return *this;
    }
    throw Ecc_Object3D_moltiplicazione_ObjectDiverso();
}

Object_3d &Object_3d::operator/(const Space &x)
{
    const Object_3d* a= dynamic_cast<const Object_3d*>(&x);
    if(a)
    {
        int val = this->getLength() / a->getLength();
        int valh = this->getHeight() / a->getHeight();
        int vald = this->getDepth() / a->getDepth();
        if(val <=0) val = 1;
        if(valh <= 0) valh = 1;
        if(vald <=0) vald = 1;
        this->setLength(val);
        this->setHeight(valh);
        this->setDepth(vald);
        this->setRisoluzione(a->getRisoluzione()); //la moltiplicazione ritorna semplicemente la risoluzione del parametro passato
        return *this;
    }
    const Object_2d* b = dynamic_cast<const Object_2d*>(&x);
    if(b)
    {
        int val = this->getLength() / b->getLength();
        int valh = this->getHeight() / b->getHeight();
        if(val <=0) val = 1;
        if(valh <= 0) valh = 1;
        this->setLength(val);
        this->setHeight(valh);
        this->setRisoluzione(b->getRisoluzione()); //la divisione ritorna semplicemente la risoluzione del parametro passato
        return *this;
    }
    const Object_1D* c = dynamic_cast<const Object_1D*>(&x);
    if(c)
    {
        //un oggetto 3 dimensioni diviso per un oggetto a una dimensione dimensione ritorna l'oggetto stesso con la lunghezza moltiplicata
        int val = this->getLength() / c->getLength();
        if(val <=0) val = 1;
        this->setLength(val);
        return *this;
    }
    throw Ecc_Object3D_divisione_ObjectDiverso();
}

Object_3d &Object_3d::operator+(const RGBHex &x)
{
    RGBHex b;
    int val = x.getColorInt() + this->col.getColorInt();
    if (val>16777215) val=16777215;
    b.setColorInt(val);
    this->setColor(b);
    return *this;
}

Object_3d &Object_3d::operator-(const RGBHex &x)
{
    RGBHex b;
    int val = col.getColorInt() - x.getColorInt();
    if(val<0) val=0;
    b.setColorInt(val);
    this->setColor(b);
    return *this;
}

Object_3d &Object_3d::operator*(const RGBHex &x)
{
    this->setColor(x);
    return *this;
}

Object_3d &Object_3d::operator/(const RGBHex &x)
{
    col.getColorInt() == x.getColorInt() ? this->setColor(RGBHex("000000")) : this->setColor(col);
    return *this;
}

void Object_3d::setLCm(double l)
{
    length = static_cast<int> (Space::dpi*(l/2.54)); // l/2.54 serve per convertire la lunghezza l da cm a pollici
    if ((Space::dpi*(l/2.54))-length > 0) length++; // Arrotondo per eccesso
}

double Object_3d::getLCm() const
{
    double a = static_cast<double>(length);
    double b = static_cast<double>(Space::dpi);
    return ((a/b)*2.54);
}

void Object_3d::setLInch(double l)
{
    length = static_cast<int> (Space::dpi*l);
    if ((Space::dpi*l)-length > 0) length++; // Arrotondo per eccesso
}

double Object_3d::getLInch() const
{
    double a = static_cast<double>(length);
    double b = static_cast<double>(length);
    return (a/b);
}

void Object_3d::setHCm(double h)
{
    height = static_cast<int> (Space::dpi*(h/2.54)); // l/2.54 serve per convertire la lunghezza l da cm a pollici
    if ((Space::dpi*(h/2.54))-height > 0) height++; // Arrotondo per eccesso
}

double Object_3d::getHCm() const
{
    double a = static_cast<double>(height);
    double b = static_cast<double>(Space::dpi);
    return ((a/b)*2.54);
}

void Object_3d::setHInch(double h)
{
    height = static_cast<int> (Space::dpi*h);
    if ((Space::dpi*h)-height > 0) height++; // Arrotondo per eccesso
}

double Object_3d::getHInch() const
{
    double a = static_cast<double>(height);
    double b = static_cast<double>(height);
    return (a/b);
}

void Object_3d::setDCm(double d)
{
    depth = static_cast<int> (Space::dpi*(d/2.54)); // l/2.54 serve per convertire la lunghezza l da cm a pollici
    if ((Space::dpi*(d/2.54))-depth > 0) depth++; // Arrotondo per eccesso
}

double Object_3d::getDCm() const
{
    double a = static_cast<double>(depth);
    double b = static_cast<double>(Space::dpi);
    return ((a/b)*2.54);
}

void Object_3d::setDInch(double d)
{
    depth = static_cast<int> (Space::dpi*d);
    if ((Space::dpi*d)-depth > 0) depth++; // Arrotondo per eccesso
}

double Object_3d::getDInch() const
{
    double a = static_cast<double>(depth);
    double b = static_cast<double>(depth);
    return (a/b);
}

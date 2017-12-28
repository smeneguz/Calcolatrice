#include "object_1d.h"

Object_1D::Object_1D() : Space(), length(1) {}

Object_1D::Object_1D(int l) : Space(), length(l) {}

Object_1D::Object_1D(int l, int risol) : Space(risol), length(l) {}

Object_1D::Object_1D(int l, int risol, RGBHex c) : Space(risol, c), length(l) {}

int Object_1D::CalcolaSuperficie()
{
    return 0; //poichè un punto o una linea non possegono superficie
}

Status Object_1D::getStatus() const
{
    Status s = Space::getStatus();
    //sistemare lunghezza
    s.l = this->getLength();
    s.lCm = this->getLCm();
    s.lInch = this->getLInch();
    return s;
}

int Object_1D::getLength() const
{
    return length;
}

void Object_1D::setLength(int l)
{
    length = l;
}

Object_1D& Object_1D::operator+(const Space &x)
{
    const Object_1D* a = dynamic_cast<const Object_1D*>(&x);
    if(a)
    {
        int val = this->getLength() + a->getLength();
        this->setLength(val);
        this->setRisoluzione(a->getRisoluzione()); //la somma ritorna semplicemente la risoluzione del parametro passato
        return *this;
    }
    //non fa niente in questo caso se non è del tipo giusto
    throw Ecc_Object1D_somma_ObjectDiverso();
}



Object_1D& Object_1D::operator-(const Space &x)
{
    const Object_1D* a = dynamic_cast<const Object_1D*>(&x);
    if(a)
    {
        int val = this->getLength() - a->getLength();
        if(val <=0) val = 1;
        this->setLength(val);
        this->setRisoluzione(a->getRisoluzione()); //la sottrazione ritorna semplicemente la risoluzione del parametro passato
        return *this;
    }
    throw Ecc_Object1D_sottrazione_ObjectDiverso();
}

Object_1D& Object_1D::operator*(const Space &x) //questo operatore viene chiamato con oggetto di inocazione di tipo Object1d quindi siamo sicuri che quello sarà il suo tipo, ritorniamo uno space
{
    const Object_1D* a = dynamic_cast<const Object_1D*>(&x);
    if(a)
    {
        int val = this->getLength() * a->getLength();
        this->setLength(val);
        this->setRisoluzione(a->getRisoluzione()); //la moltiplicazione ritorna semplicemente la risoluzione del parametro passato
        return *this;
    }
    throw Ecc_Object1D_moltiplicazione_ObjectDiverso();

}



Object_1D& Object_1D::operator/(const Space &x)
{    
    const Object_1D* a = dynamic_cast<const Object_1D*>(&x);
    if(a)
    {
        int val = this->getLength() / a->getLength();
        if(val <=0) val = 1;
        this->setLength(val);
        this->setRisoluzione(a->getRisoluzione()); //la moltiplicazione ritorna semplicemente la risoluzione del parametro passato
        return *this;
    }

    throw Ecc_Object1D_divisione_Object1D();
}

Object_1D& Object_1D::operator+(const RGBHex &x)
{
    RGBHex b;
    int val = x.getColorInt() + this->col.getColorInt();
    if (val>16777215) val=16777215;
    b.setColorInt(val);
    this->setColor(b);
    return *this;
}

Object_1D& Object_1D::operator-(const RGBHex &x)
{
    RGBHex b;
    int val = col.getColorInt() - x.getColorInt();
    if(val<0) val=0;
    b.setColorInt(val);
    this->setColor(b);
    return *this;
}

Object_1D& Object_1D::operator*(const RGBHex &x)
{
    this->setColor(x);
    return *this;
}

Object_1D& Object_1D::operator/(const RGBHex &x)
{
    col.getColorInt() == x.getColorInt() ? this->setColor(RGBHex("000000")) : this->setColor(col);
    return *this;


}

void Object_1D::setLCm(double l)
{
    length = static_cast<int> (Space::dpi*(l/2.54)); // l/2.54 serve per convertire la lunghezza l da cm a pollici
    if ((Space::dpi*(l/2.54))-length > 0) length++; // Arrotondo per eccesso
}

double Object_1D::getLCm() const
{
    double a = static_cast<double>(length);
    double b = static_cast<double>(Space::dpi);
    return ((a/b)*2.54);
}

void Object_1D::setLInch(double l)
{
    length = static_cast<int> (Space::dpi*l);
    if ((Space::dpi*l)-length > 0) length++; // Arrotondo per eccesso
}

double Object_1D::getLInch() const
{
    double a = static_cast<double>(length);
    double b = static_cast<double>(length);
    return (a/b);
}

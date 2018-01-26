#include "space.h"

Space::Space()
{
    Space::dpi = 72;
    Space::col = *(new RGBHex());

}

Space::Space(int d)
{
    Space::dpi = d;
    Space::col = *(new RGBHex());
}

Space::Space(int d, RGBHex c)
{
    Space::dpi = d;
    Space::col = c;
}

void Space::setRisoluzione(int d)
{
    Space::dpi = d;

}

int Space::getRisoluzione() const
{
    return Space::dpi;
}

void Space::setColor(RGBHex c)
{
    Space::col = c;
}

RGBHex Space::getColor() const
{
    return Space::col;
}

Status Space::getStatus() const
{
    Status* s = new Status();
    s->dpi = this->getRisoluzione();
    s->color = this->getColor().getColor(); //il ptimo mi ritorna un rgb e get color di rgb mi ritorna una stringa
    return *s;
}



Space::~Space(){}

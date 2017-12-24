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



Space::~Space(){}

#ifndef SPACE_H
#define SPACE_H

#include "rgbhex.h"
/**
 * @brief La classe astratta Space rappresenta il concetto di spazi dimenensionali di Oggetti, i quali poi hanno una risoluzione di stampa e un colore
 */
class Space {
private:
    int dpi; // risoluzione di stampa che sarà poi definita in modo opportuno nelle sottoclassi
    RGBHex* col; // instanzio una classe colore

public:
    //space è una classe astratta e quindi l'utilizzo dei costruttori sarà utile solo per la costruzione del sottoogetto -> non ci sarà mai un'istanza di space
    virtual ~Space();
    Space();
    Space(int d);
    Space(int d, RGBHex* c);

    //metodi get e set
    void setRisoluzione(int d);
    int getRisoluzione() const;
    void setColor(RGBHex c);
    RGBHex getColor() const;

    //guardare se è necessario fare anxhe operatori tra Space e Space


    // Overloading di operatori
    Space operator+(const RGBHex& x);
    Space operator-(const RGBHex& x);
    Space operator*(const RGBHex& x);
    Space operator/(const RGBHex& x);
};

#endif // SPACE_H

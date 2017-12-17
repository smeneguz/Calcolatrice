#ifndef SPACE_H
#define SPACE_H

#include "rgbhex.h"

class Space {
private:
    int dpi; // risoluzione di stampa che sarà poi definita in modo opportuno nelle sottoclassi
    rgbHex col; // instanzio una classe colore

public:
    //space è una classe astratta e quindi l'utilizzo dei costruttori sarà utile solo per la costruzione del sottoogetto -> non ci sarà mai un'istanza di space
    virtual ~Space;
    Space();
    Space(int d);
    Space(int d, rgbHex c);

    //metodi get e set
    void setRisoluzione(int d);
    int getRisoluzione() const;
    void setColor(rgbHex c);
    rgbHex getColor() const;

    //guardare se è necessario fare anxhe operatori tra Space e Space


    // Overloading di operatori
   virtual Space operator+(const rgbHex& x);
   virtual Space operator-(const rgbHex& x);
   virtual Space operator*(const rgbHex& x);
   virtual Space operator/(const rgbHex& x);
};

#endif // SPACE_H

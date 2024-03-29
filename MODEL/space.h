#ifndef SPACE_H
#define SPACE_H
#include <iostream>
#include "rgbhex.h"
#include "exceptions.h"
#include "object.h"

/**
 * @brief La classe astratta Space rappresenta il concetto di spazi dimenensionali di Oggetti, i quali poi hanno una risoluzione di stampa e un colore
 */
class Space : public Object {
protected:
    int dpi; // risoluzione di stampa che sarà poi definita in modo opportuno nelle sottoclassi
    RGBHex col; // oggetto di tipo colore

public:
    virtual int getLength() const = 0;

    //space è una classe astratta e quindi l'utilizzo dei costruttori sarà utile solo per la costruzione del sottoogetto -> non ci sarà mai un'istanza di space
    //virtual ~Space(); eredito da Obbject
    Space();
    Space(int d);
    Space(int d, RGBHex c);

    //metodi get e set
    void setRisoluzione(int d);
    int getRisoluzione() const;
    void setColor(RGBHex c);
    RGBHex getColor() const;

    //informazioni
    virtual Status getStatus() const;

    virtual int CalcolaSuperficie() = 0;
    //guardare se è necessario fare anxhe operatori tra Space e Space

    // metodi space + - * / colore
    virtual Space& operator+(const RGBHex& x) = 0;
    virtual Space& operator-(const RGBHex& x) = 0;
    virtual Space& operator*(const RGBHex& x) = 0;
    virtual Space& operator/(const RGBHex& x) = 0;

    //metodi space + * - /  space
    virtual Space& operator+(const Space& x) = 0;
    virtual Space& operator-(const Space& x) = 0;
    virtual Space& operator*(const Space& x) = 0;
    virtual Space& operator/(const Space& x) = 0;
    //idea overriding metodi con specializzazione per le classi, poi cast dei parametri e invocazione degli operatori giusti nella parte privata nel caso siano dello stesso tipo
};

#endif // SPACE_H

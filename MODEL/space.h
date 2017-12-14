#ifndef SPACE_H
#define SPACE_H

#include "rgbhex.h"

class Space {
private:
    int dpi; // risoluzione di stampa che sarà poi definita in modo opportuno nelle sottoclassi
    rgbHex col; // instanzio una classe colore

public:
    //space è una classe astratta e quindi l'utilizzo dei costruttori sarà utile solo per la costruzione del sottoogetto -> non ci sarà mai un'istanza di space

    Space();
    Space(int d, rgbHex c);
};

#endif // SPACE_H

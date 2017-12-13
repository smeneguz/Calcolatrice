#ifndef RGB_H
#define RGB_H

#include "colore.h"

class rgb : public Colore{
public:
    rgb();
    rgb(std::string c);
    rgb(int r, int g, int b);

    //metodi set e get
    void setColor(std::string c);
    void setColorInt(int color);
    std::string getColor() const;
    int getColorInt() const;


    //set rgb




    /* DA IMPLEMENTARE
     * virtual std::string getHex() const = 0;
     * virtual ~Colore()=0;
     * virtual Colore* clone() const =0;
     *
     */

};

#endif // RGB_H

#include "rgbhex.h"

const char RGBHex::c[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

//costruttore vuoto
RGBHex::RGBHex() {
    RGBHex::color = 0;
}

////////DA RIVEDERE//////////////////////////////////////////////////////////////////////
    std::string RGBHex::puliStringa(std::string s, int n) {
    std::string rawInput = s;
    std::string input = "";
    std::string car;
    std::string suffisso = "";
    for (int i=0; i<n;i++) suffisso+="0";
    // "Pulisco" la stringa di input da eventuali valori NON esadecimali
    for (int i=(rawInput.size()-1); i>=0; i--) {
        car = rawInput[i];
        if ((car.compare("9")<=0 && car.compare("0")>=0) ||
            (car.compare("f")<=0 && car.compare("a")>=0) ||
            (car.compare("F")<=0 && car.compare("A")>=0)) {
            // Se il carattere � compreso fra 'a' e 'f' lo metto maiuscolo, sottraendo 32 posizioni della tabella ASCII
            if ((car.compare("f")<=0 && car.compare("a")>=0)) car = car[0]-32;
            input = ""+car+input;
        }
    }
    input = suffisso+input;
    input = input.substr(input.size()-n,n);
    return input;
}

//
int RGBHex::valueOf(std::string c, int n) {
    std::string s = puliStringa(c,n);
    std::string car;
    int colore = 0;
    int val;
    for (int i=0; i<n; i++) {
        car = s[(n-1)-i];
        if ((car.compare("9")<=0 && car.compare("0")>=0)) val = 0+car[0]-48;
        else val = 10+car[0]-65;
        colore += val*(static_cast<int>(pow(16,i)));
    }
    return colore;
}

///////////////////////////////////////////////////////////////////////////////

//costruisco RGBHex tramite una stringa, controllando che rispetti i canoni
RGBHex::RGBHex(std::string c) {
    RGBHex::color = valueOf(c,6);
}

//dati i valori r g b costruisco RGBHex in modo consistente
RGBHex::RGBHex(int r, int g, int b) {
    if (r<0) r=0;
    if (r>255) r=255;
    if (g<0) g=0;
    if (g>255) g=255;
    if (b<0) g=0;
    if (b>255) g=255;
    int c = b + g*256 + r*65536;
    RGBHex::color = c;
}

// FUNZIONI SET E GET //

//setto color tramite stringa
void RGBHex::setColor(std::string c) {
    RGBHex::color = valueOf(c,6);
}

//get color formato string (1048576 = RGB  16, 0, 0)
std::string RGBHex::getColor() const {
    std::string output = "";
    int x = RGBHex::color;
    int y = x;
    int div = 1048576;
    for (int i=0; i<6; i++) {
        y = x/div;
        x = x%div;
        output += RGBHex::c[y];
        div = div/16;
    }
    return output;
}

//setta il colore dicendo che nel caso l'inero passato sia > 16777215 allora lo pone a 16777215 (white) && c < 0 allora lo pongo = 0 (black)
void RGBHex::setColorInt(int c) {
    RGBHex::color = c;
    if (c>16777215) RGBHex::color = 16777215;
    else if (c<0) RGBHex::color = 0;
}

//ritorno color
int RGBHex::getColorInt() const {
    return RGBHex::color;
}

RGBHex* RGBHex::clone() const{
    return new RGBHex(*this);
}

RGBHex& RGBHex::operator-(const Color& x) {
    return *(clone());
}

RGBHex& RGBHex::operator+(const Color& x) {
    return *(clone());
}

RGBHex& RGBHex::operator/(const Color& x) {
    return *(clone());
}

RGBHex& RGBHex::operator*(const Color& x) {
    return *(clone());
}

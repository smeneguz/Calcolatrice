#include "rgbhex.h"

const char RGBHex::c[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};


//funzione che restituisce un intero partendo da una stringa esadecimale
/*int RGBHex::HexToInt(std::string hex) const
{
    int result = 0;
    for (int i=0; i<hex.length(); i++) {
        if (hex[i]>=48 && hex[i]<=57)
        {
            result += (hex[i]-48)*pow(16,hex.length()-i-1);
        } else if (hex[i]>=65 && hex[i]<=70) {
            result += (hex[i]-55)*pow(16,hex.length( )-i-1);
        } else if (hex[i]>=97 && hex[i]<=102) {
            result += (hex[i]-87)*pow(16,hex.length()-i-1);
        }
    }
    return result;
}
*/
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
            // Se il carattere è compreso fra 'a' e 'f' lo metto maiuscolo, sottraendo 32 posizioni della tabella ASCII
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

////////////////////////////////////////////////
/// \brief RGBHex::setRint
/// \param r
///
void RGBHex::setRint(int r) {
    int x = r;
    if (x>255) x=255;
    else if (x<0) x=0;
    x=x*65536; // moltiplico x (valore fra 0 e 255) per 16^4, in questo modo il numero influirà solo sulla prima e seconda cifra hex
    RGBHex::color = RGBHex::color%65536; // Rimuovo la prima e seconda cifre hex più significative
    RGBHex::color += x;
}

///
/// \brief RGBHex::setGint
/// \param g
///
void RGBHex::setGint(int g) {
    int x = g;
    if (x>255) x=255;
    else if (x<0) x=0;
    x=x*256; // moltiplico x (valore fra 0 e 255) per 16^2, in questo modo il numero influirà solo sulla terza e quarta cifra hex
    RGBHex::color = RGBHex::color-(RGBHex::color%65536)+(RGBHex::color%256); // Rimuovo la 3^ e 4^ cifre hex più significative
    RGBHex::color += x;
}

///
/// \brief RGBHex::setBint
/// \param b
///
void RGBHex::setBint(int b) {
    int x = b;
    if (x>255) x=255;
    else if (x<0) x=0;
    RGBHex::color = RGBHex::color-(RGBHex::color%256); // Rimuovo la 5^ e 6^ cifre hex pi� significative
    RGBHex::color += x;
}

// divido per 16^4 in modo da ottenere la prima e seonda cifra hex
int RGBHex::getRint() const {
    return RGBHex::color/65536;
}

// get G (terza e quarta)
int RGBHex::getGint() const {
    return (RGBHex::color%65536)/256;
}

// get B (quinta e sesta)
int RGBHex::getBint() const {
    return RGBHex::color%256;
}

Status RGBHex::getStatus() const
{
    Status s = Status();
    s.color = this->getColor();
    return s;
}

////////////////////////////////////////////////////////////////
// SET R G B////
void RGBHex::setR(std::string r) {
    (*this).RGBHex::setRint(valueOf(r,2));
}

void RGBHex::setG(std::string g) {
     (*this).RGBHex::setGint(valueOf(g,2));
}

void RGBHex::setB(std::string b) {
     (*this).RGBHex::setBint(valueOf(b,2));
}

// GET R G B ///
std::string RGBHex::getR() const {
    std::string output = "";
    int x = RGBHex::color;
    int y = x;
    int div = 1048576;
    for (int i=0; i<2; i++) {
        y = x/div;
        x = x%div;
        output += RGBHex::c[y];
        div = div/16;
    }
    return output;
}

std::string RGBHex::getG() const {
    std::string output = "";
    int x = RGBHex::color%65536;
    int y = x;
    int div = 4096;
    for (int i=0; i<2; i++) {
        y = x/div;
        x = x%div;
        output += RGBHex::c[y];
        div = div/16;
    }
    return output;
}

std::string RGBHex::getB() const {
    std::string output = "";
    int x = RGBHex::color%256;
    int y = x;
    int div = 16;
    for (int i=0; i<2; i++) {
        y = x/div;
        x = x%div;
        output += RGBHex::c[y];
        div = div/16;
    }
    return output;
}



//////////////////OVERLOADING OPERATORI //////
//operatori di somma e sottrazione oparano sul colore in forma intera
//mentre operatori di moltiplicazione e divisione fanno operazioni sui singoli elementi R G e B facendo sottrazioni o somme in base all'operazione
RGBHex RGBHex::operator-(const RGBHex& x){
    RGBHex aux;
    int result = RGBHex::color - x.RGBHex::getColorInt();
    if (result<0) result = -(result); // abs(result)
    if (result>16777215) aux.setColorInt(16777215);
    else aux.setColorInt(result);
    return aux;

}

RGBHex RGBHex::operator+(const RGBHex& x) {
    RGBHex aux;
    int result = RGBHex::color + x.RGBHex::getColorInt();
    if (result>16777215) aux.setColorInt(16777215);
    else if (result<0) aux.setColorInt(0);
    else aux.setColorInt(result);
    return aux;
}

RGBHex RGBHex::operator/(const RGBHex& x) {
    int r = this->getRint() - x.getRint();
    if (r<0) r = 0;
    if (r>255) r=255;
    int g = this->getGint() - x.getGint();
    if (g<0) g = 0;
    if (g>255) g=255;
    int b = this->getBint() - x.getBint();
    if (b<0) b = 0;
    if (b>255) b=255;
    RGBHex aux = RGBHex(r,g,b);
    return aux;
}
/*
RGBHex& RGBHex::somma(const StrategyColor& x){
    //sono qua e quinidi sia this che x sono entrambi RGBHex
    int result = RGBHex::color + x.getColorInt();
    if (result>16777215) x.setColorInt(16777215);
    else if (result<0) x.setColorInt(0);
    else x.setColorInt(result);
    return x;
}
*/

RGBHex RGBHex::operator*(const RGBHex& x) {
    int r = this->getRint() + x.getRint();
    if (r<0) r = 0;
    if (r>255) r=255;
    int g = this->getGint() + x.getGint();
    if (g<0) g = 0;
    if (g>255) g=255;
    int b = this->getBint() + x.getBint();
    if (b<0) b = 0;
    if (b>255) b=255;
    RGBHex aux = RGBHex(r,g,b);
    return aux;
}

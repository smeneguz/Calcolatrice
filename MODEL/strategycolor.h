#ifndef COLORE_H
#define COLORE_H

#include<iostream>
/**
 * @brief la classe Color svolge il compito di interfaccia per permettere estensibilità
 */
class StrategyColor{


public:
   // virtual std::string getHex() const = 0;
    virtual ~StrategyColor();
    virtual StrategyColor* clone() const =0;

    // operatori che verranno chiamati e implementati nella classe rgb
    virtual StrategyColor& operator+(const StrategyColor& x) = 0;
    virtual StrategyColor& operator-(const StrategyColor& x) = 0;
    virtual StrategyColor& operator*(const StrategyColor& x) = 0;
    virtual StrategyColor& operator/(const StrategyColor& x) = 0;

};

#endif // COLORE_H

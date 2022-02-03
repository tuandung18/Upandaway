#ifndef SCHALTER_H
#define SCHALTER_H

#include "knoten.h"

class Schalter : public knoten
{
public:
    Schalter();
    double Abfrage () ;
    void Setzen (double d) ;
    void Einheit();
    void Name();
    bool getZustand() const;
    void setZustand(bool newZustand);

private:
    double Zustand;
};

#endif // SCHALTER_H

#ifndef LICHTSENSOR_H
#define LICHTSENSOR_H

#include "knoten.h"

class Lichtsensor : public knoten
{
public:
    Lichtsensor();
    double Abfrage ();
    void Setzen (double d) ;
    void Einheit();
    void Name();
};

#endif // LICHTSENSOR_H

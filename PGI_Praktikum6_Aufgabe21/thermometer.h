#ifndef THERMOMETER_H
#define THERMOMETER_H

#include "knoten.h"

class Thermometer : public knoten
{
public:
    Thermometer();
    double Abfrage () ;
    void Setzen (double d) ;
    void Einheit();
    void Name();
};

#endif // THERMOMETER_H

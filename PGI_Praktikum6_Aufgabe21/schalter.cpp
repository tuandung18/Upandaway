#include "schalter.h"
#include <iostream>
using namespace std;
Schalter::Schalter()
{
    Zustand=0;
}

double Schalter::Abfrage()
{
    return Zustand;

}


void Schalter::Setzen(double d)
{
    if(d==0 or d==1)
        Zustand = d;
    else
        cout <<"Falsche Eingabe!"<<endl;
}

void Schalter::Einheit()
{
    cout<<endl;
}

void Schalter::Name()
{
    cout << "Schalter";
}

bool Schalter::getZustand() const
{
    return Zustand;
}

void Schalter::setZustand(bool newZustand)
{
    Zustand = newZustand;
}

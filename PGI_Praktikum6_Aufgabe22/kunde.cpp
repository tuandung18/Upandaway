#include "kunde.h"
int Kunde::count = 0;
Kunde::Kunde()
{
    count++;
    nr=count;
}

int Kunde::getNr() const
{
    return nr;
}

void Kunde::setNr(int newNr)
{
    nr = newNr;
}






#include "produkt.h"

Produkt::Produkt(int s, double p, std::string n)
{
    nr = s;
    preis = p;
    name = n;
}

double Produkt::getPreis() const
{
    return preis;
}

int Produkt::getNr() const
{
    return nr;
}

const std::string &Produkt::getName() const
{
    return name;
}

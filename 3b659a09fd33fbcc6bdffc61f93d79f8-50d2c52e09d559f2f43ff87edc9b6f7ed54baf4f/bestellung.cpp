#include "bestellung.h"


int Bestellung::getBestellungsNummer() const
{
    return bestellungsNummer;
}

const Kunde &Bestellung::getKunde() const
{
    return kunde;
}

const std::vector<Produkt> &Bestellung::getProdukte() const
{
    return produkte;
}

void Bestellung::addProdukt(Produkt p)
{
    produkte.push_back(p);
}

double Bestellung::getGesamtPreis()
{
    double preis = 0;
    for (size_t i = 0; i < produkte.size(); i++) {
        preis += produkte[i].getPreis();
    }
    return preis;
}

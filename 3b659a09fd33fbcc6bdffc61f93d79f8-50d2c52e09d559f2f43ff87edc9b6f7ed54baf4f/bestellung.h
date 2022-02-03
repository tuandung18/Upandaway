#ifndef BESTELLUNG_H
#define BESTELLUNG_H

#include <vector>
#include "kunde.h"
#include "produkt.h"


class Bestellung
{
public:
    Bestellung(int bestellNr, Kunde k)
        : bestellungsNummer{bestellNr}
        , kunde{k}
    {}

    int getBestellungsNummer() const;

    const Kunde &getKunde() const;

    const std::vector<Produkt> &getProdukte() const;

    void addProdukt(Produkt p);

    double getGesamtPreis();

private:
    int bestellungsNummer;
    Kunde kunde;
    std::vector<Produkt> produkte;

};

#endif // BESTELLUNG_H

#ifndef BESTELLSYSTEM_H
#define BESTELLSYSTEM_H

#include <vector>
#include "kunde.h"
#include "katalog.h"
#include "bestellung.h"


class Bestellsystem
{
public:
    Bestellsystem();

    int getAnzahlKunden() const;

    bool addKunde(Kunde k);

    bool addBestellung(Bestellung b);

    void printKundenList();

    void printProductList();

    void printBestellungList();

    void printBestellungsInfo(int bnr);

    Kunde getKunde(int knr);

    Produkt getProdukt(int sku);

    Bestellung getBestellung(int bnr);

    bool existsKunde(int knr);

    bool existsProdukt(int sku);

    bool existsBestellung(int bnr);

    int getAnzahlBestellungen() const;

private:
    Katalog produktKatalog;
    std::vector<Kunde> kunden;
    std::vector<Bestellung> bestellungen;

    int anzahlKunden;
    int anzahlBestellungen;

    int indexOfKunde(int kundenNummer);
    int indexOfBestellung(int bnr);

private:
};

#endif // BESTELLSYSTEM_H

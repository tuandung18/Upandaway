#include "bestellsystem.h"

Bestellsystem::Bestellsystem()
{
    produktKatalog = Katalog();

}

int Bestellsystem::getAnzahlKunden() const
{
    return anzahlKunden;
}

bool Bestellsystem::addKunde(Kunde k)
{
    if (indexOfKunde(k.getKundennummer()) == -1) {
        kunden.push_back(k);
        anzahlKunden++;
        return true;
    }
    return false;
}

bool Bestellsystem::addBestellung(Bestellung b)
{
    if (!existsBestellung(b.getBestellungsNummer())) {
        bestellungen.push_back(b);
        return true;
    }
    return false;
}





Kunde Bestellsystem::getKunde(int knr)
{
    if (indexOfKunde(knr) != -1) {
        return kunden[indexOfKunde(knr)];
    }

}

Produkt Bestellsystem::getProdukt(int sku)
{
    return produktKatalog.getProdukt(sku);
}

Bestellung Bestellsystem::getBestellung(int bnr)
{
    if (indexOfBestellung(bnr) != -1) {
        return bestellungen[indexOfBestellung(bnr)];
    }

}

bool Bestellsystem::existsKunde(int knr)
{
    if (indexOfKunde(knr) != -1) {
        return true;
    }
    return false;
}

bool Bestellsystem::existsProdukt(int sku)
{
    return produktKatalog.existsProdukt(sku);
}

bool Bestellsystem::existsBestellung(int bnr)
{
    if (indexOfBestellung(bnr) != -1) {
        return true;
    }
    return false;
}

int Bestellsystem::getAnzahlBestellungen() const
{
    return anzahlBestellungen;
}

int Bestellsystem::indexOfKunde(int kundenNummer)
{
    for (size_t i = 0; i < kunden.size(); i++) {
        if (kunden[i].getKundennummer() == kundenNummer) {
            return i;
        }
    }
    return -1;
}

int Bestellsystem::indexOfBestellung(int bnr)
{
    for (size_t i = 0; i < bestellungen.size(); i++) {
        if (bestellungen[i].getBestellungsNummer() == bnr) {
            return i;
        }
    }
    return -1;
}
void Bestellsystem::printBestellungsInfo(int bnr)
{
    if (existsBestellung(bnr)) {
        Bestellung b = getBestellung(bnr);
        std::cout << "Bestellung: " << b.getBestellungsNummer() << " fuer: " << b.getKunde().getKundennummer() << ": " << b.getKunde().getVorname() << ", " << b.getKunde().getNachname() << std::endl;
        std::cout << std::endl << "Produkte: " << std::endl;

        for (size_t i = 0; i < b.getProdukte().size(); i++) {
            std::cout << b.getProdukte()[i].getName() << " (Nr: " << b.getProdukte()[i].getNr() << "), Preis: " << b.getProdukte()[i].getPreis() << std::endl;
        }
        std::cout << std::endl  << b.getGesamtPreis() << " EUR";
    } else {
        std::cout << "Bestellung: " << bnr << " existiert nicht!" << std::endl;
    }
}
void Bestellsystem::printKundenList()
{
    for (size_t i = 0; i < kunden.size(); i++) {
        std::cout << "KundenNummer: " << kunden[i].getKundennummer() << " Vorname: " << kunden[i].getVorname() << ", Preis: " << kunden[i].getNachname() << std::endl;
    }
}
void Bestellsystem::printProductList()
{
    produktKatalog.printProductList();
}
void Bestellsystem::printBestellungList()
{
    for (size_t i = 0; i < bestellungen.size(); i++) {
        std::cout << "BestellNR: " << bestellungen[i].getBestellungsNummer() << ", Preis: " << bestellungen[i].getGesamtPreis() << std::endl;
    }
}

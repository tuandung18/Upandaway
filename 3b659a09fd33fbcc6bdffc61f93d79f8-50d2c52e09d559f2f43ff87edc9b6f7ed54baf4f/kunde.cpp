#include "kunde.h"

Kunde::Kunde(int kn, std::string vn, std::string nn)
{
    kundennummer = kn;
    vorname = vn;
    nachname = nn;
}

int Kunde::getKundennummer() const
{
    return kundennummer;
}

const std::string &Kunde::getVorname() const
{
    return vorname;
}

const std::string &Kunde::getNachname() const
{
    return nachname;
}

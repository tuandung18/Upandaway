#ifndef KUNDE_H
#define KUNDE_H

#include <string>

class Kunde
{
public:
    Kunde(int kn, std::string vn, std::string nn);

    int getKundennummer() const;

    const std::string &getVorname() const;

    const std::string &getNachname() const;

private:
    std::string vorname, nachname;
    int kundennummer;
};

#endif // KUNDE_H

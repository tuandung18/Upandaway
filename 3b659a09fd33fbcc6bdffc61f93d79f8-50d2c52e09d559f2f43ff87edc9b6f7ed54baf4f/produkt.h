#ifndef PRODUKT_H
#define PRODUKT_H

#include <string>


class Produkt
{
public:
    Produkt(int s, double p, std::string n);

    double getPreis() const;

    int getNr() const;

    const std::string &getName() const;

private:
    double preis;
    int nr;
    std::string name;
};

#endif // PRODUKT_H

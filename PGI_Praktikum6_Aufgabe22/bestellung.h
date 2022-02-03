#ifndef BESTELLUNG_H
#define BESTELLUNG_H

#include "kunde.h"
#include "produkt.h"
#include <vector>
#include <memory>
class Bestellung : virtual public Kunde
{
public:
    static int cnt;
    Bestellung();


    void addP(Produkt newP);
    int getNr() const;

    const Kunde &getK() const;
    void setK(const Kunde &newK);
    void print();
    std::vector<Produkt> &getP() ;

private:
    int nr;
    Kunde k;
    std::vector<Produkt> p;
};

#endif // BESTELLUNG_H

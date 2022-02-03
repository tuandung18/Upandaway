#ifndef PRODUKT_H
#define PRODUKT_H
#include <memory>
#include "katalog.h"
enum product {burger=1,doener,pasta,cola,fanta,sprite};
class Produkt : public Katalog
{
public:
    Produkt();
    Produkt(Katalog k,product name);
    product getName() const;
    void setName(product newName);

private:
    product name;
    Katalog k;

};

#endif // PRODUKT_H

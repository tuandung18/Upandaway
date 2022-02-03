#ifndef KATALOG_H
#define KATALOG_H

#include <vector>
#include <iostream>
#include "produkt.h"


class Katalog
{
public:
    Katalog();
    void printProductList();
    bool existsProdukt(int pnr);
    Produkt getProdukt(int sku);

private:
    std::vector<Produkt> products;
    int indexOfProdukt(int sku);
};

#endif // KATALOG_H

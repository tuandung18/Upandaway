#include "katalog.h"

Katalog::Katalog()
{

    products.push_back(Produkt(1, 10.00, "Produkt 1"));
    products.push_back(Produkt(2, 12.34, "Dienstleistung 1"));
    products.push_back(Produkt(3, 100.00, "Produkt 2"));

}

void Katalog::printProductList()
{
    for (size_t i = 0; i < products.size(); i++) {
        std::cout << "Produkt: " << products[i].getNr() << " Name: " << products[i].getName() << ", Preis: " << products[i].getPreis() << std::endl;
    }
}

bool Katalog::existsProdukt(int pnr)
{
    if (indexOfProdukt(pnr) != -1) {
        return true;
    }
    return false;
}

Produkt Katalog::getProdukt(int sku)
{
    if (indexOfProdukt(sku) != -1) {
        return products[indexOfProdukt(sku)];
    }
    throw std::invalid_argument( "Diese ProduktNummer existiert nicht!" );
}



int Katalog::indexOfProdukt(int sku)
{
    for (size_t i = 0; i < products.size(); i++) {
        if (products[i].getNr() == sku) {
            return i;
        }
    }
    return -1;
}

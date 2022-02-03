#include "produkt.h"

Produkt::Produkt()
{

}

Produkt::Produkt(Katalog k, product name)
    :name(name),k(k)
{

}

product Produkt::getName() const
{
    return name;
}

void Produkt::setName(product newName)
{
    name = newName;
}

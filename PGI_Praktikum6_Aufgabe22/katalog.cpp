#include "katalog.h"

Katalog::Katalog()
{

}

Katalog::Katalog(Typ t)
    :t(t)
{

}

Typ Katalog::getT() const
{
    return t;
}

void Katalog::setT(Typ newT)
{
    t = newT;
}



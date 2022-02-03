#ifndef KATALOG_H
#define KATALOG_H
class Produkt;
enum Typ {food=1,drink};
class Katalog
{
public:
    Katalog();
    Katalog(Typ);
    Typ getT() const;
    void setT(Typ newT);


private:
    Typ t;

};

#endif // KATALOG_H

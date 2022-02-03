#ifndef KUNDE_H
#define KUNDE_H


#include <vector>
class Kunde
{
public:
    Kunde();
    static int count;
    int getNr() const;
    void setNr(int newNr);





private:
    int nr;

};

#endif // KUNDE_H

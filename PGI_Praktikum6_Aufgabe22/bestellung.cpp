#include "bestellung.h"
int Bestellung::cnt=0;
#include<iostream>
#include "string.h"
using namespace std;
Bestellung::Bestellung()
{
    cnt++;
    nr=cnt;
}



void Bestellung::addP(Produkt newP)
{
    p.push_back(newP);
}

int Bestellung::getNr() const
{
    return nr;
}

const Kunde &Bestellung::getK() const
{
    return k;
}

void Bestellung::setK(const Kunde &newK)
{
    k = newK;
}

void Bestellung::print()
{
    std::cout<< "Bestellung nummer "  + std::to_string(nr) + ": "<<std::endl;
    int i = 1;
    for(Produkt pr : p){
        cout<<to_string(i) + " ";
        cout<<pr.getName()<<endl;
        switch (pr.getName()) {
        case 1:
            cout<< "Burger"<<endl;
            break;
        case 2:
            cout<<"Doener"<<endl;
            break;
        case 3:
            cout<<"Pasta"<<endl;
            break;
        case 4:
            cout<<"Cola"<<endl;break;
        case 5:
            cout<<"Fanta"<<endl;break;
        case 6:
            cout<<"Sprite"<<endl;break;
        }
        i++;
    }
}

std::vector<Produkt> &Bestellung::getP()
{
    return p;
}

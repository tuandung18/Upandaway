#include <iostream>
#include "bestellung.h"
#include "produkt.h"
#include "string.h"
using namespace std;
void choose (Bestellung b,int y){


    switch (y) {
    case 1:
        cout<<"1.Burger\n2.Doener\n3.Pasta\n";
        int z;
        cin>>z;
        switch (z) {
        case 1:{
            Katalog ka = Katalog(food);
            Produkt pr = Produkt(ka,burger);
            b.getP().push_back(pr);
            cout<<&b.getP()[0];
            break;
        }
        case 2:
            b.addP(Produkt(Katalog(food),doener));
            break;
        case 3:
               b.addP(Produkt(Katalog(food),pasta));
            break;
        default:break;
        }
        break;

    case 2:
        cout<<"1.Cola\n2.Fanta\n3.Sprite\n";
        int d;
        cin>>d;
        switch (d) {
        case 1:
            b.addP(Produkt(Katalog(drink),cola));
            break;
        case 2:
              b.addP(Produkt(Katalog(drink),fanta));
            break;
        case 3:
              b.addP(Produkt(Katalog(drink),sprite));
            break;
        }
        break;
    case 3:
        b.print();
        break;

    default: break;
    }
}
int main()
{
    bool run=1;
    do {
        cout << "Bitte waehlen Sie:\n1.Als Kunde einlogen.\n2.Als Mitarbeiter einlogen.\n3.Auslogen\n";
        int x;
        cin >> x;
        switch (x) {
        case 1:{
            Kunde k= Kunde();
            Bestellung b = Bestellung();
            b.setK(k);
            cout<<b.cnt<<endl;
            cout<<"Kundennummber " + to_string(k.count) + ": "<<endl;
            bool c =1;
            do{
                cout<<"1.Essen.\n2.Getraenk.\n3.Liste schauen\n4.Beende\n";
                int y;
                cin>>y;
                if(y==4){
                    c=0;
                }
                choose(b,y);
            } while(c);
            break;
        }
        case 2:
            cout<<"Nur Mitarbeiter duerfen hier einlogen"<<endl;
            break;
        default:break;
        case 3:
            run=0;
            break;
        }

    } while (run);

}

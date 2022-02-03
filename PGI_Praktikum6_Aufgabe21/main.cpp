
#include "gateway.h"
#include <iostream>
using namespace std;
bool run = 1;
void arbeiten(knoten* k){
    cout << "'a': Abfragen des Zustands."<<endl;
    cout<<"'s': Setzen des Zustands."<<endl;
    cout<<"'x': Beenden."<<endl;
    char c; cin >> c;
    switch (c) {
    case 'a':
        k->Name();
        cout<<": "<<k->Abfrage();
        k->Einheit();
        break;
    case 's':
        cout<<"Eingabe nur fuer Schalter, sonst 0"<<endl;
        int y;
        cin >> y;
        k->Setzen(y);
        break;
    case 'x': run =0;
        break;
    default:cout<<"Falsche Eingabe"<<endl;

    }
}
int main()
{
    gateway g = gateway();
    cout << "Knotenliste: "<<endl;
    int j=1;
    for(int i =0;i<5;i++){
        cout<<j<<". ";
        g.getK()[i]->Name();
        cout<<"\n";
        j++;
    }
    while (run==1) {
        cout<<"Welche Knoten: ";
        int c; cin >>c;
        if(c==0){
            run=0;
            break;
        }
        else arbeiten(g.getKnoten(c));
    }

    return 0;
}

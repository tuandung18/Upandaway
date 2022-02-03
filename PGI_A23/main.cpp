#include <iostream>
#include "knoten.h"
using namespace std;
Knoten copy(Knoten* k) {
    if (k == NULL) {
        return *k;
    } else {
       Knoten temp = copy(k->getNext());
       temp.drauflegen(k->getInfo());
       return temp;
    }
}
int main()
{
    Knoten *ablage;
        int n,x;
        cout << "Wieviele Werte?: ";
        cin >> n;
        for (int i=0; i<n; i++) {
            cout << "Int eingeben: ";
            cin >> x;
            ablage->drauflegen(x);
        }
        Knoten* t = ablage;
        for (int i=0; i<n; i++) {
            cout<<t->getInfo()<<endl;
            t=t->getNext();
        }
        Knoten ablage2 = copy(ablage);
        return 0;

}

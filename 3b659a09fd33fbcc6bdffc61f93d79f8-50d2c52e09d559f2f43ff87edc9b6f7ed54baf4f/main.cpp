#include <iostream>
#include "bestellsystem.h"
#include "kunde.h"
#include "bestellung.h"

using namespace std;

char menu() {

        cout << "1: Bestellung aufgeben" << endl
         << "2: Bestellung ausgeben" << endl
         << "3: Kundenkonto" << endl
         << "4: Kunden listen" << endl
         << "5: Bestellungen listen" << endl
         << "6: Produkt listen" << endl
         << "" << endl
         << "Auswahl: ";

    char c; cin >> c; return c;
}
int main()
{
    Bestellsystem b = Bestellsystem();

    bool end = false;
    while (!end) {
        switch (menu()) {

        case '1': {
            cout << endl << "neue Bestellnummer: ";
            int bnr; cin >> bnr;
            if (bnr == -1) {
                bnr = b.getAnzahlBestellungen()+1;
            }

            if (b.existsBestellung(bnr)) {
                cout << "Bestellnummer existiert bereits!" << endl;
                break;
            }

            cout << "KundenNummer: ";
            int knr; cin >> knr;
            if (!b.existsKunde(knr)) {
                cout << "Kundenummer existiert nicht!" << endl;
                break;
            }

            Bestellung neueBestellung = Bestellung(bnr, b.getKunde(knr));
            cout << "weitere Produktnr: " << endl;
            bool prodEnd = false;
            while (!prodEnd) {
                cout << "+: ";
                int p;
                cin >> p;
                if (p != -1) {
                    if (b.existsProdukt(p)) {
                        neueBestellung.addProdukt(b.getProdukt(p));
                        cout << " Produkt " << p << " (" << b.getProdukt(p).getName() << ") hinzugefuegt!" << endl;
                    } else {
                        cout << "ProduktNummer existiert nicht!" << endl;
                    }
                } else {
                    prodEnd = true;
                }
            }
            cout << endl << "Kunde: " << b.getKunde(knr).getKundennummer() << ": " << b.getKunde(knr).getVorname() << ", " << b.getKunde(knr).getNachname() << endl;
            cout << endl << "Produkte: " << endl;

            for (size_t i = 0; i < neueBestellung.getProdukte().size(); i++) {
                cout << neueBestellung.getProdukte()[i].getName() << " (Nr: " << neueBestellung.getProdukte()[i].getNr() << "), Preis: " << neueBestellung.getProdukte()[i].getPreis() << endl;
            }

            cout << endl << "GesamtPreis: " << neueBestellung.getGesamtPreis() << " EUR";


            cout << endl << endl << "Bestellung aufgeben?: \ny.yes\nn.no";
            char execute; cin >> execute;
            switch (execute) {
            case 'y': {
                if (b.addBestellung(neueBestellung)) {
                    cout << endl << "Neue Bestellung erfolgreich aufgegeben" << endl << endl;
                }
                break;
            }

            default:
                cout << endl << "Aufgeben der Bestellung abgebrochen!!!" << endl << endl;
            }
            break;
        }
        case '2': {
            cout << endl << "Bestellnummer: ";
            int bnr; cin >> bnr;
            cout << endl;
            b.printBestellungsInfo(bnr);
            break;
        }
        case '3': {
            cout << endl << endl << "Vornamen: ";
            string vn, nn;
            cin >> vn;
            cout << endl << "Nachnamen: ";
            cin >> nn;
            cout << endl << "Kundennummer: ";
            int knr; cin >> knr;
            if (knr == -1) {
                knr = b.getAnzahlKunden()+1;
            }

            if (!b.addKunde(Kunde(knr, vn, nn))) {
                cout << endl << "Diese Kundennummer existiert bereits!";
            }

            break;
        }
        case '4': {
            cout << endl << endl << "Kundenliste:" << endl;
            b.printKundenList();
            break;
        }
        case '5': {
            cout << endl << endl << "Bestellungen:" << endl;
            b.printBestellungList();
            break;
        }
        case '6': {
            cout << endl << endl << "Kundenliste:" << endl;
            b.printProductList();
            break;
        }
        }
    }
    return 0;
}

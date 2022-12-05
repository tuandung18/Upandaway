#include "travelagency.h"
#include <iostream>
#include <fstream>
#include <flightbooking.h>
#include<rentalcarreservation.h>
#include<hotelbooking.h>
using namespace std;
const vector<Booking *> &TravelAgency::getBookings() const
{
    return bookings;
}

void TravelAgency::setBookings(const vector<Booking *> &newBookings)
{
    bookings = newBookings;
}

TravelAgency::TravelAgency()
{

}

void TravelAgency::readFile(string sourceName)
{
    ifstream source;
    string line;
    int lineNumber = 0;
    source.open(sourceName.c_str(), ios:: in);
    if (!source) {
    cerr << sourceName << " kann nicht geoeffnet werden!\n";
    exit(-1);
    }
    else {
        cout << "Opening file succesful" << endl;
    }

    int countF=0, countH=0, countR=0;
    double priceF=0.0,priceH=0.0,priceR=0.0;

    while(getline(source,line)){
        int numberOfCol = 0;
        lineNumber++;
        vector<string> daten;
        string temp;
        for  (char const &ch: line) {
            if(&ch == &line.back()){
                temp.push_back(ch);
                daten.push_back(temp);
                temp.clear();
                numberOfCol++;
            }
            if(ch== '|' ){
                daten.push_back(temp);
                temp.clear();
                numberOfCol++;
                continue;
            }
            temp.push_back(ch);

        }

        string typ = daten[0];
        if(typ=="H" && numberOfCol!=7)
            throw invalid_argument("Number of attributes is not enough at line " + to_string(lineNumber));
        else if( (typ=="F" || typ=="R") && numberOfCol!=8)
        {
            throw invalid_argument("Number of attributes is not enough at line " + to_string(lineNumber));
        }
        if(typ=="F"){
            Booking* booking = new FlightBooking (daten[5],daten[6],daten[7]);
            if(daten[5].size()!=3 || daten[6].size()!=3)
                throw invalid_argument("Wrong airport names at line " + to_string(lineNumber));
            booking->setId(stoi( daten[1]));
            booking->setFromDate(daten[3]);
            booking->setToDate(daten[4]);
            string tempPrice = daten[2];

            auto it = tempPrice.begin();/* this block is to check double type*/
               while (it != tempPrice.end() && (std::isdigit(*it) || *it == '.')) {
                   it++;
               }
               if(tempPrice.empty() || it != tempPrice.end())
                throw invalid_argument("Wrong price type at line " + to_string(lineNumber));

               booking->setPrice(stod(daten[2]));
            bookings.push_back(booking);
            countF++;
            priceF+=booking->getPrice();
//            cout<<booking->showDetails()<<endl;
        }
        if(typ=="H"){
            Booking* booking = new HotelBooking (daten[5],daten[6]);
            booking->setId(stoi( daten[1]));
            booking->setFromDate(daten[3]);
            booking->setToDate(daten[4]);
            booking->setPrice(stod(daten[2]));
            bookings.push_back(booking);
            countH++;
            priceH+=booking->getPrice();
//            cout<<booking->showDetails()<<endl;
        }
        if(typ=="R"){
            Booking* booking = new RentalCarReservation (daten[5],daten[6],daten[7]);
            booking->setId(stoi( daten[1]));
            booking->setFromDate(daten[3]);
            booking->setToDate(daten[4]);
            booking->setPrice(stod(daten[2]));
            bookings.push_back(booking);
            countR++;
            priceR+=booking->getPrice();
//            cout<<booking->showDetails()<<endl;
        }



    }
    source.close();
    cout << "Es wurden " + to_string(countF) + " Flugbuchungen im Wert von " + to_string(priceF) + " Euro und " + to_string(countR) + " Mietwagenbuchungen im Wert von " + to_string(priceR) + " Euro und " + to_string(countH) + " Hotelreservierungen im Wert von " + to_string(priceH) + " Euros angelegt."<<endl;
}
string TravelAgency::readFile2(string sourceName)
{
    ifstream source;
    string line;
    int lineNumber = 0;
    source.open(sourceName.c_str(), ios:: in);
    if (!source) {
        cerr << sourceName << " kann nicht geoeffnet werden!\n";
        exit(-1);
    }
    else {
        cout << "Opening file succesfully" << endl;
    }

    int countF=0, countH=0, countR=0;
    double priceF=0.0,priceH=0.0,priceR=0.0;

    while(getline(source,line)){
        int numberOfCol = 0;
        lineNumber++;
        vector<string> daten;
        string temp;
        for  (char const &ch: line) {
            if(&ch == &line.back()){
                temp.push_back(ch);
                daten.push_back(temp);
                temp.clear();
                numberOfCol++;
            }
            if(ch== '|' ){
                daten.push_back(temp);
                temp.clear();
                numberOfCol++;
                continue;
            }
            temp.push_back(ch);

        }

        string typ = daten[0];
        if(typ=="H" && numberOfCol!=7)
            throw invalid_argument("Number of attributes is not enough at line " + to_string(lineNumber));
        else if( (typ=="F" || typ=="R") && numberOfCol!=8)
        {
            throw invalid_argument("Number of attributes is not enough at line " + to_string(lineNumber));
        }
        if(typ=="F"){
            Booking* booking = new FlightBooking (daten[5],daten[6],daten[7]);
            if(daten[5].size()!=3 || daten[6].size()!=3)
                throw invalid_argument("Wrong airport names at line " + to_string(lineNumber));
            booking->setType(typ);
            booking->setId(stoi( daten[1]));
            booking->setFromDate(daten[3]);
            booking->setToDate(daten[4]);
            string tempPrice = daten[2];

            auto it = tempPrice.begin();/* this block is to check double type*/
            while (it != tempPrice.end() && (std::isdigit(*it) || *it == '.')) {
                it++;
            }
            if(tempPrice.empty() || it != tempPrice.end())
                throw invalid_argument("Wrong price type at line " + to_string(lineNumber));

            booking->setPrice(stod(daten[2]));
            bookings.push_back(booking);
            countF++;
            priceF+=booking->getPrice();
            //            cout<<booking->showDetails()<<endl;
        }
        if(typ=="H"){
            Booking* booking = new HotelBooking (daten[5],daten[6]);
            booking->setType(typ);
            booking->setId(stoi( daten[1]));
            booking->setFromDate(daten[3]);
            booking->setToDate(daten[4]);
            booking->setPrice(stod(daten[2]));
            bookings.push_back(booking);
            countH++;
            priceH+=booking->getPrice();
            //            cout<<booking->showDetails()<<endl;
        }
        if(typ=="R"){
            Booking* booking = new RentalCarReservation (daten[5],daten[6],daten[7]);
            booking->setType(typ);
            booking->setId(stoi( daten[1]));
            booking->setFromDate(daten[3]);
            booking->setToDate(daten[4]);
            booking->setPrice(stod(daten[2]));
            bookings.push_back(booking);
            countR++;
            priceR+=booking->getPrice();
            //            cout<<booking->showDetails()<<endl;
        }



    }
    source.close();
    string result =  "Es wurden " + to_string(countF) + " Flugbuchungen im Wert von " + to_string(priceF) + " Euro und " + to_string(countR) + " Mietwagenbuchungen im Wert von " + to_string(priceR) + " Euro und " + to_string(countH) + " Hotelreservierungen im Wert von " + to_string(priceH) + " Euros angelegt.";
    return result;
}
void TravelAgency::readBinaryFile(string sourceName)
{
    ifstream source;

    string line;


    source.open(sourceName.c_str(), ios:: in | ios:: binary);
    if (!source) {
    cerr << sourceName << " kann nicht geoeffnet werden!\n";
    exit(-1);
    }
    else {
        cout << "Opening file succesful" << endl;
    }
    int countF=0, countH=0, countR=0;
    double priceF=0.0,priceH=0.0,priceR=0.0;
    Booking* bestFlight = nullptr;
    Booking* bestHotel = nullptr;
    Booking* bestCar = nullptr;
    double bestF = 0.0,bestH = 0.0,bestR = 0.0;

    do {
        char typ;
        source.read(reinterpret_cast<char*>(&typ), sizeof (typ));
        long id;
        double price;
        char fromFlughafen[3],toFlughafen[3];
        char hotel[15], town[15], startStation[15], returnStation[15], company[15];
        char fromDate[8], toDate[8];
        source.read(reinterpret_cast<char*>(&id), sizeof (long));
        source.read(reinterpret_cast<char*>(&price), sizeof (double));
        source.read(reinterpret_cast<char*>(&fromDate), sizeof (fromDate));
        source.read(reinterpret_cast<char*>(&toDate), sizeof (toDate));
        Booking* booking = nullptr;
        switch(typ)
        {
        case 'F':
            source.read(reinterpret_cast<char*>(&fromFlughafen), sizeof (fromFlughafen));
            source.read(reinterpret_cast<char*>(&toFlughafen), sizeof (toFlughafen));
            source.read(reinterpret_cast<char*>(&company), sizeof (company));
            booking = new FlightBooking (fromFlughafen, toFlughafen, company);
            booking->setPrice(price);
            countF++;
            priceF+=booking->getPrice();
            if (bestF<booking->getPrice()) {
                bestF=booking->getPrice();
                bestFlight = booking;
            }
            break;

        case 'H':
            source.read(reinterpret_cast<char*>(&hotel), sizeof (hotel));
            source.read(reinterpret_cast<char*>(&town), sizeof (town));
            booking = new HotelBooking (string(hotel,hotel+15), string(town,town+15));

            booking->setPrice(price);
            countH++;
            priceH+=booking->getPrice();
            if (bestH<booking->getPrice()){

                bestH=booking->getPrice();
                bestHotel = booking;
            }
            break;


        case 'R':
            source.read(reinterpret_cast<char*>(&startStation), sizeof (startStation));
            source.read(reinterpret_cast<char*>(&returnStation), sizeof (returnStation));
            source.read(reinterpret_cast<char*>(&company), sizeof (company));
            booking = new RentalCarReservation (string(startStation, startStation+15), string(returnStation,returnStation+15), string(company,company+15));

            booking->setPrice(price);
            countR++;
            priceR+=booking->getPrice();
            if (bestR<booking->getPrice()) {
                bestR=booking->getPrice();
                bestCar=booking;
            }

            break;

        default:
            delete booking;
            break;
        }
        if(booking!=nullptr){
            booking->setId(id);
            booking->setFromDate(string(fromDate,fromDate+8));
            booking->setToDate(string(toDate,toDate+8));
            bookings.push_back(booking);
            //cout<<booking->showDetails()<<endl;
        }
        else delete booking;

    } while (!source.eof());

    source.close();


    cout << "Es wurden " + to_string(countF) + " Flugbuchungen im Wert von " + to_string(priceF) + " Euro und " + to_string(countR) + " Mietwagenbuchungen im Wert von " + to_string(priceR) + " Euro und " + to_string(countH) + " Hotelreservierungen im Wert von " + to_string(priceH) + " Euros angelegt."<<endl;
    cout << "Teuerste Flugbuchung: " + bestFlight->showDetails()<<endl;
    cout << "Teuerste Hotelbuchung: " + bestHotel->showDetails()<<endl;
    cout << "Teuerste Autobuchung: " + bestCar->showDetails()<<endl;

}

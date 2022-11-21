#include "travelagencyui.h"
#include "ui_travelagencyui.h"
#include <flightbooking.h>
#include<rentalcarreservation.h>
#include<hotelbooking.h>

travelAgencyUI::travelAgencyUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::travelAgencyUI)
{
    ui->setupUi(this);
    changeWindowName();
    ui->Information->setTabText(0,"Flugbuchung");
    ui->Information->setTabText(1,"Hotelbuchung");
    ui->Information->setTabText(2,"Autobuchung");


}

travelAgencyUI::~travelAgencyUI()
{
    delete ui;
}
void travelAgencyUI::readFile(string sourceName)
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
string travelAgencyUI::readFile2(string sourceName)
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

void travelAgencyUI::setBookings(const vector<Booking *> &newBookings)
{
    bookings = newBookings;
}

void travelAgencyUI::changeWindowName()
{
    setWindowTitle("Up and away");
}
void travelAgencyUI::on_readFile_clicked()
{
    Popup* pop = new Popup;
    QFileDialog* q = new QFileDialog;
    QString fileName = q->getOpenFileName();
    QMessageBox* messageBox = new QMessageBox;
    try{

        messageBox->about(this,"Datei erfolgreich eingelesen", QString::fromStdString(readFile2(fileName.toStdString())));

        delete pop;
    }
    catch(invalid_argument i)
    {
        pop->about(this,"Fehler beim Einlesen der Buchungen",QString::fromStdString(i.what()));
        pop->show();

    }
    delete messageBox;
    delete q;

}




void travelAgencyUI::on_showBooking_clicked()
{
    if(bookings.size()==0)
    {
        QMessageBox* message = new QMessageBox;
        message->about(this,QString::fromStdString("Error finding"),QString::fromStdString("No booking"));
        delete message;
    }
    else
    {
        idInput* idInput = new class idInput;
        idInput->show();
        idInput->exec();
        idInput->getSavedID();
        int id = idInput->getSavedID();
        //    std::cout<<bookings.size()<<endl;

        bool found=false;
        for(auto &b : bookings)
        {
            if(b->getId() == id)
            {
                vector<string> details = b->getDetails();
                switch ( b->getType().back()) {
                case 'F':
                    ui->FID->setText(QString::fromStdString(to_string(b->getId())));
                    ui->FSDate->setText(b->setQDate(b->getFromDate()).toString("dd.MM.yyyy"));
                    ui->FEDate->setText(b->setQDate(b->getToDate()).toString("dd.MM.yyyy"));

                    ui->FSFlughafen->setText(QString::fromStdString(details[0]));
                    ui->FEFlugafen->setText(QString::fromStdString(details[1]));
                    ui->FCompany->setText(QString::fromStdString(details[2]));
                    ui->FPrice->setText(QString::fromStdString(details[3]));
                    break;
                case 'R':
                    ui->AID->setText(QString::fromStdString(to_string(b->getId())));
                    ui->ASDate->setText(b->setQDate(b->getFromDate()).toString("dd.MM.yyyy"));
                    ui->AEDate->setText(b->setQDate(b->getToDate()).toString("dd.MM.yyyy"));



                    ui->ASStation->setText(QString::fromStdString(details[0]));
                    ui->AEStation->setText(QString::fromStdString(details[1]));
                    ui->ACompany->setText(QString::fromStdString(details[2]));
                    ui->APrice->setText(QString::fromStdString(details[3]));
                    break;
                case 'H':
                    ui->HID->setText(QString::fromStdString(to_string(b->getId())));
                    ui->HSDate->setText(b->setQDate(b->getFromDate()).toString("dd.MM.yyyy"));
                    ui->HEDate->setText(b->setQDate(b->getToDate()).toString("dd.MM.yyyy"));


                    ui->HHotel->setText(QString::fromStdString(details[0]));
                    ui->HStadt->setText(QString::fromStdString(details[1]));
                    ui->HPrice->setText(QString::fromStdString(details[2]));
                    break;
                default:
                    cerr<<"Wrong type"<<endl;
                    break;
                }
                found = true;

            }

        }
        if(!found)
        {
            QMessageBox* message = new QMessageBox;
            message->about(this,QString::fromStdString("Buchung mit ID " + to_string(id)),QString::fromStdString("ID not found"));
            delete message;
        }


    }
}


void travelAgencyUI::on_inputID_clicked()
{

}





void travelAgencyUI::on_showAllBooking_clicked()
{
    if(bookings.empty())
    {
        QMessageBox* message = new QMessageBox;
        message->about(this,QString::fromStdString("No booking"),QString::fromStdString("No booking given"));
        delete message;
    }
    for(auto &b : bookings)
    {
        QListWidgetItem* i = new QListWidgetItem(QString::fromStdString(b->showDetails()));
        i->setData(Qt::UserRole,QVariant(QString::fromStdString(to_string(b->getId()))));
        ui->bookings->addItem(i);
    }
}


void travelAgencyUI::on_bookings_itemClicked(QListWidgetItem *item)
{
    QString savedID = item->data(Qt::UserRole).toString();
    for(auto &b : bookings)
    {

            if(QString::fromStdString(to_string(b->getId())) == savedID)
            {
                vector<string> details = b->getDetails();
                switch ( b->getType().back()) {
                case 'F':
                    ui->FID->setText(QString::fromStdString(to_string(b->getId())));
                    ui->FSDate->setText(b->setQDate(b->getFromDate()).toString("dd.MM.yyyy"));
                    ui->FEDate->setText(b->setQDate(b->getToDate()).toString("dd.MM.yyyy"));

                    ui->FSFlughafen->setText(QString::fromStdString(details[0]));
                    ui->FEFlugafen->setText(QString::fromStdString(details[1]));
                    ui->FCompany->setText(QString::fromStdString(details[2]));
                    ui->FPrice->setText(QString::fromStdString(details[3]));
                    ui->Information->setCurrentIndex(0);
                    break;
                case 'R':
                    ui->AID->setText(QString::fromStdString(to_string(b->getId())));
                    ui->ASDate->setText(b->setQDate(b->getFromDate()).toString("dd.MM.yyyy"));
                    ui->AEDate->setText(b->setQDate(b->getToDate()).toString("dd.MM.yyyy"));



                    ui->ASStation->setText(QString::fromStdString(details[0]));
                    ui->AEStation->setText(QString::fromStdString(details[1]));
                    ui->ACompany->setText(QString::fromStdString(details[2]));
                    ui->APrice->setText(QString::fromStdString(details[3]));
                    ui->Information->setCurrentIndex(2);
                    break;
                case 'H':
                    ui->HID->setText(QString::fromStdString(to_string(b->getId())));
                    ui->HSDate->setText(b->setQDate(b->getFromDate()).toString("dd.MM.yyyy"));
                    ui->HEDate->setText(b->setQDate(b->getToDate()).toString("dd.MM.yyyy"));


                    ui->HHotel->setText(QString::fromStdString(details[0]));
                    ui->HStadt->setText(QString::fromStdString(details[1]));
                    ui->HPrice->setText(QString::fromStdString(details[2]));
                    ui->Information->setCurrentIndex(1);
                    break;
                default:
                    cerr<<"Wrong type"<<endl;
                    break;
                }

            }
    }
}


void travelAgencyUI::on_saveData_clicked()
{
    if(bookings.empty())
    {
        QMessageBox* message = new QMessageBox;
        message->about(this,QString::fromStdString("No booking"),QString::fromStdString("No booking given"));
        delete message;
    }
    QJsonDocument jsonDocument;
    QJsonArray flugBuchung,hotelBuchung,autoBuchung,buchungen;
    QJsonObject list;
    for(auto &b : bookings){
        if(b->getType().back()=='F')
        {
            QJsonObject flight;
            vector<string> detail = b->getDetails();
            flight["airline"] = QString::fromStdString(detail[2]);
            flight["fromDate"] = QString::fromStdString(b->getFromDate());
            flight["fromDest"] = QString::fromStdString(detail[0]);
            flight["id"] = QString::fromStdString(to_string(b->getId()));
            flight["price"] = stoi(detail[3]);
            flight["toDate"] = QString::fromStdString(b->getToDate());
            flight["toDes"] = QString::fromStdString(detail[1]);
            flugBuchung.push_back(flight);
        }
        if(b->getType().back()=='R')
        {
            QJsonObject car;
            vector<string> detail = b->getDetails();
            car["company"] = QString::fromStdString(detail[2]);
            car["fromDate"] = QString::fromStdString(b->getFromDate());
            car["pickupLocation"] = QString::fromStdString(detail[0]);
            car["id"] = QString::fromStdString(to_string(b->getId()));
            car["price"] = stoi(detail[3]);
            car["returnLocation"] = QString::fromStdString(detail[1]);
            car["toDate"] = QString::fromStdString(b->getToDate());
            autoBuchung.push_back(car);

        }
        if(b->getType().back()=='H')
        {
            QJsonObject hotel;
            vector<string> detail = b->getDetails();
            hotel["fromDate"] = QString::fromStdString(b->getFromDate());
            hotel["hotel"] = QString::fromStdString(detail[0]);
            hotel["id"] = QString::fromStdString(to_string(b->getId()));
            hotel["price"] = stoi(detail[2]);
            hotel["toDate"] = QString::fromStdString(b->getToDate());
            hotel["town"] = QString::fromStdString(detail[1]);
            hotelBuchung.push_back(hotel);
        }
    }
    list["Flugbuchungen"] = flugBuchung;

    list["Mietwagenreservierungen"] = autoBuchung;

    list["Hotelbuchungen"] = hotelBuchung;
    buchungen.push_back(list);
    jsonDocument.setArray(buchungen);
    QFileDialog* q = new QFileDialog;
    QString name = q->getSaveFileName(this);
    QFile datei(name);
    if(!datei.open(QIODevice::ReadWrite))
        std::cerr<<"Datei konnte nicht geoeffnet werden"<<endl;
    else
        cout<<"File opened"<<endl;
    datei.resize(0);
    datei.write(jsonDocument.toJson());
    datei.close();
    delete q;
}


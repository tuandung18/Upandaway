#include "travelagencyui.h"
#include "ui_travelagencyui.h"
#include <flightbooking.h>
#include<rentalcarreservation.h>
#include<hotelbooking.h>
#include<algorithm>
#include<myqtablewidgetitem.h>
#include<qstring.h>




travelAgencyUI::travelAgencyUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::travelAgencyUI)
{
    ui->setupUi(this);
    changeWindowName();


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

    int countF=0, countH=0, countR=0, countTravel = 0, countCustomer = 0;
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

        if(findBooking(stol(daten[1]))==nullptr) //check if booking with this id exists
        {
            string typ = daten[0];
            if(typ=="H" && numberOfCol!=10)
                throw invalid_argument("Number of attributes is not enough at line " + to_string(lineNumber));
            else if( (typ=="F" || typ=="R") && numberOfCol!=11)
            {
                throw invalid_argument("Number of attributes is not enough at line " + to_string(lineNumber));
            }
            if(typ=="F"){

                Booking* booking = new FlightBooking (daten[8],daten[9],daten[10]);
                if(daten[8].size()!=3 || daten[9].size()!=3)
                    throw invalid_argument("Wrong airport names at line " + to_string(lineNumber));
                booking->setType(typ);
                booking->setId(stoi( daten[1]));
                booking->setFromDate(daten[3]);
                booking->setToDate(daten[4]);
                booking->setTravelID(5);
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
                Booking* booking = new HotelBooking (daten[8],daten[9]);
                booking->setType(typ);
                booking->setId(stoi( daten[1]));
                booking->setFromDate(daten[3]);
                booking->setToDate(daten[4]);
                booking->setPrice(stod(daten[2]));
                booking->setTravelID(5);
                bookings.push_back(booking);
                countH++;
                priceH+=booking->getPrice();
                //            cout<<booking->showDetails()<<endl;
            }
            if(typ=="R"){
                Booking* booking = new RentalCarReservation (daten[8],daten[9],daten[10]);
                booking->setType(typ);
                booking->setId(stoi( daten[1]));
                booking->setFromDate(daten[3]);
                booking->setToDate(daten[4]);
                booking->setPrice(stod(daten[2]));
                booking->setTravelID(5);
                bookings.push_back(booking);
                countR++;
                priceR+=booking->getPrice();
                //            cout<<booking->showDetails()<<endl;
            }
            //TODO: find a way to get booking out of if-statements

            /*
             * Now we check if travelid and customerid
             * already exist
             * */
            if(findTravel(stol(daten[5]))==nullptr)
            {
                Travel* travel = new Travel(stol(daten[5]),stol(daten[6]));
                countTravel++;
                allTravels.push_back(travel);
            }

            findTravel(stol(daten[5]))->addBooking(findBooking(stol(daten[1])));

            if(findCustomer(stol(daten[6]))==nullptr)
            {
                Customer* customer = new Customer(stol(daten[6]),daten[7]);
                countCustomer++;
                allCustomers.push_back(customer);
            }

            findCustomer(stol(daten[6]))->addTravel(findTravel(stol(daten[5])));

        }

    }
    source.close();
    string result =  "Es wurden " + to_string(countF) + " Flugbuchungen im Wert von " + to_string(priceF) + " Euro und "
            + to_string(countR) + " Mietwagenbuchungen im Wert von " + to_string(priceR) + " Euro und "
            + to_string(countH) + " Hotelreservierungen im Wert von "
            + to_string(priceH) + " Euros angelegt. Es wurden "
            + to_string(countTravel) + " Reisen und "
            + to_string(countCustomer) + " Kunden angelegt. Der Kunde mit der ID 1 hat "
            + to_string(findCustomer(1)->getTravelList().size()) + " Reisen gebucht. Zur Reise mit der ID 17 gehören "
            + to_string(findTravel(17)->getTravelBookings().size()) + " Buchungen."
            ;
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
{}

void travelAgencyUI::on_inputID_clicked()
{

}

void travelAgencyUI::on_showAllBooking_clicked()
{

}


void travelAgencyUI::on_bookings_itemClicked(QListWidgetItem *item)
{}


void travelAgencyUI::on_saveData_clicked()
{
    //    if(bookings.empty())
    //    {
    //        QMessageBox* message = new QMessageBox;
    //        message->about(this,QString::fromStdString("No booking"),QString::fromStdString("No booking given"));
    //        delete message;
    //    }
    //    else{QJsonDocument jsonDocument;
    //        QJsonArray flugBuchung,hotelBuchung,autoBuchung,buchungen;
    //        QJsonObject list;
    //        for(auto &b : bookings){
    //            if(b->getType().back()=='F')
    //            {
    //                QJsonObject flight;
    //                vector<string> detail = b->getDetails();
    //                flight["airline"] = QString::fromStdString(detail[2]);
    //                flight["fromDate"] = QString::fromStdString(b->getFromDate());
    //                flight["fromDest"] = QString::fromStdString(detail[0]);
    //                flight["id"] = QString::fromStdString(to_string(b->getId()));
    //                flight["price"] = stoi(detail[3]);
    //                flight["toDate"] = QString::fromStdString(b->getToDate());
    //                flight["toDes"] = QString::fromStdString(detail[1]);
    //                flugBuchung.push_back(flight);
    //            }
    //            if(b->getType().back()=='R')
    //            {
    //                QJsonObject car;
    //                vector<string> detail = b->getDetails();
    //                car["company"] = QString::fromStdString(detail[2]);
    //                car["fromDate"] = QString::fromStdString(b->getFromDate());
    //                car["pickupLocation"] = QString::fromStdString(detail[0]);
    //                car["id"] = QString::fromStdString(to_string(b->getId()));
    //                car["price"] = stoi(detail[3]);
    //                car["returnLocation"] = QString::fromStdString(detail[1]);
    //                car["toDate"] = QString::fromStdString(b->getToDate());
    //                autoBuchung.push_back(car);

    //            }
    //            if(b->getType().back()=='H')
    //            {
    //                QJsonObject hotel;
    //                vector<string> detail = b->getDetails();
    //                hotel["fromDate"] = QString::fromStdString(b->getFromDate());
    //                hotel["hotel"] = QString::fromStdString(detail[0]);
    //                hotel["id"] = QString::fromStdString(to_string(b->getId()));
    //                hotel["price"] = stoi(detail[2]);
    //                hotel["toDate"] = QString::fromStdString(b->getToDate());
    //                hotel["town"] = QString::fromStdString(detail[1]);
    //                hotelBuchung.push_back(hotel);
    //            }
    //        }
    //        list["Flugbuchungen"] = flugBuchung;

    //        list["Mietwagenreservierungen"] = autoBuchung;

    //        list["Hotelbuchungen"] = hotelBuchung;
    //        buchungen.push_back(list);
    //        jsonDocument.setArray(buchungen);
    //        QFileDialog* q = new QFileDialog;
    //        QString name = q->getSaveFileName(this);
    //        QFile datei(name);
    //        if(!datei.open(QIODevice::ReadWrite))
    //            std::cerr<<"Datei konnte nicht geoeffnet werden"<<endl;
    //        else
    //            cout<<"File opened"<<endl;
    //        datei.resize(0);
    //        datei.write(jsonDocument.toJson());
    //        datei.close();
    //        delete q;
    //    }
}

void travelAgencyUI::setTravelAgency(TravelAgency *newTravelAgency)
{
    travelAgency = newTravelAgency;
}

Booking *travelAgencyUI::findBooking(long id)
{
    for(auto &b : bookings){
        if(b->getId()==id)
            return b;
    }
    return nullptr;
}

Travel *travelAgencyUI::findTravel(long id)
{
    for(auto &t : allTravels){
        if(t->getId()==id)
            return t;
    }
    return nullptr;
}

Customer *travelAgencyUI::findCustomer(long id)
{
    for(auto &c : allCustomers){
        if(c->getId()==id)
            return c;
    }
    return nullptr;
}


void travelAgencyUI::on_Customer_clicked()
{
    QTableWidget* tableWidget = ui->tableWidget;
    if(bookings.empty())
    {
        QMessageBox* message = new QMessageBox;
        message->about(this,QString::fromStdString("No booking"),QString::fromStdString("No booking given"));
        delete message;
    }

    else{idInput*id = new idInput;
        id->show();
        id->exec();

        tableWidget->setColumnCount(3);
        int row = 0;
        if(findCustomer(id->getSavedID())==nullptr)
        {
            QMessageBox* message = new QMessageBox;
            message->about(this,QString::fromStdString("Customer not found"),QString::fromStdString("No customer with this ID found"));

            delete message;
        }
        else{

            Customer* customer = findCustomer(id->getSavedID());
            ui->customerName->setText(QString::fromStdString(customer->getName()));
            for(auto &t : customer->getTravelList())
            {
                tableWidget->insertRow(row);
                tableWidget->setItem(row,0,new MyQTableWidgetItem(QString::fromStdString(to_string(t->getId()))));
                tableWidget->setItem(row,1,new MyQTableWidgetItem(QString::fromStdString(t->soonestBooking()->getFromDate())));
                tableWidget->setItem(row,2 ,new MyQTableWidgetItem(QString::fromStdString(t->latestBooking()->getToDate())));

                row++;

            }
        }
    }

}






void travelAgencyUI::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{

}

void travelAgencyUI::on_tableWidget_cellDoubleClicked(int row, int column)
{


    QTableWidget* tableWidget2 = ui->tableWidget_2;
    QString travelID = ui->tableWidget->item(row,0)->text();
    ui->travelID->setText("Travel ID : " +travelID);
    tableWidget2->setColumnCount(4);
    int bookingTableRow = 0;
    if(findTravel(travelID.toLong())==nullptr)
    {
        QMessageBox* message = new QMessageBox;
        message->about(this,QString::fromStdString("Travel not found"),QString::fromStdString("No travek with this ID found"));

        delete message;
    }
    else{
        tableWidget2->clearContents();

        Travel* travel = findTravel(travelID.toLong());

        for(auto &b : travel->getTravelBookings())
        {
            tableWidget2->insertRow(bookingTableRow);
            tableWidget2->setItem(bookingTableRow ,0,new MyQTableWidgetItem(QString::fromStdString(to_string(b->getId()))));
            tableWidget2->setItem(bookingTableRow ,1,new MyQTableWidgetItem(QString::fromStdString(b->getFromDate())));
            tableWidget2->setItem(bookingTableRow ,2 ,new MyQTableWidgetItem(QString::fromStdString(b->getToDate())));
            tableWidget2->setItem(bookingTableRow ,3 ,new MyQTableWidgetItem(QString::fromStdString(to_string(b->getPrice()))));

            bookingTableRow ++;

        }
        tableWidget2->setRowCount(bookingTableRow);
    }

}



void travelAgencyUI::on_tableWidget_2_cellDoubleClicked(int row, int column)
{
    QTableWidget* tableWidget3 = ui->tableWidget_3;
    QTableWidget* tableWidget4 = ui->tableWidget_4;
    QString bookingID = ui->tableWidget_2->item(row,0)->text();
    Booking* booking = findBooking(bookingID.toLong());
    if(booking->getType().back()=='F' or booking->getType().back()=='R')
    {
        ui->tabWidget->setCurrentIndex(0);
        for(int i = 0; i<tableWidget3->rowCount();i++)
        {

            tableWidget3->setItem(i,0,new MyQTableWidgetItem(QString::fromStdString(booking->getDetails().at(i))));
        }
    }
    if(booking->getType().back()=='H')
    {
        ui->tabWidget->setCurrentIndex(1);
        for(int i = 0; i<tableWidget4->rowCount();i++)
        {
            {

                tableWidget4->setItem(i,0,new MyQTableWidgetItem(QString::fromStdString(booking->getDetails().at(i))));
            }
        }
    }

}


void travelAgencyUI::on_pushButton_clicked()
{
    if(ui->tableWidget_3->item(0,0)!=nullptr)
    {Booking* b1 = findBooking(ui->tableWidget_3->item(0,0)->text().toLong());
        if(b1->getType().back()=='F')
        {
            b1->setFromDate(ui->tableWidget_3->item(1,0)->text().toStdString());
            b1->setToDate(ui->tableWidget_3->item(2,0)->text().toStdString());
            b1->setFromDestination(ui->tableWidget_3->item(3,0)->text().toStdString());
            b1->setToDestination(ui->tableWidget_3->item(4,0)->text().toStdString());
            b1->setAirline(ui->tableWidget_3->item(5,0)->text().toStdString());
            b1->setPrice(ui->tableWidget_3->item(6,0)->text().toDouble());

        }
        if(b1->getType().back()=='R')
        {
            b1->setFromDate(ui->tableWidget_3->item(1,0)->text().toStdString());
            b1->setToDate(ui->tableWidget_3->item(2,0)->text().toStdString());
            b1->setPickupLocation(ui->tableWidget_3->item(3,0)->text().toStdString());
            b1->setReturnLocation(ui->tableWidget_3->item(4,0)->text().toStdString());
            b1->setCompany(ui->tableWidget_3->item(5,0)->text().toStdString());
            b1->setPrice(ui->tableWidget_3->item(6,0)->text().toDouble());

        }
    }

    if(ui->tableWidget_4->item(0,0)!=nullptr)
    {
        Booking* b2 = findBooking(ui->tableWidget_4->item(0,0)->text().toLong());
        if(b2->getType().back()=='H')
        {
            b2->setFromDate(ui->tableWidget_4->item(1,0)->text().toStdString());
            b2->setToDate(ui->tableWidget_4->item(2,0)->text().toStdString());
            b2->setHotel(ui->tableWidget_4->item(3,0)->text().toStdString());
            b2->setTown(ui->tableWidget_4->item(4,0)->text().toStdString());
            b2->setPrice(ui->tableWidget_4->item(5,0)->text().toDouble());
        }
    }

}
void swap (QTableWidgetItem* row1, QTableWidgetItem* row2)
{
    QTableWidgetItem temp = *row1;
       *row1 = *row2;
       *row2 = temp;

}

void travelAgencyUI::sort(int columm, QTableWidget* table)
{
    int i,j;
    for(i=0;i<table->rowCount()-1;i++)
    {
        for(j=0;j<table->rowCount()-i-1;j++)
        {
            if(table->item(j,columm)->text().toDouble()>table->item(j+1,columm)->text().toDouble())
            {
                for(int k = 0; k < table->columnCount();k++)
                    swap(table->item(j,k),table->item(j+1,k));
            }
        }
    }
}
void travelAgencyUI::on_pushButton_2_clicked()
{
    sort(0,ui->tableWidget);
}



void travelAgencyUI::on_pushButton_3_clicked()
{
    sort(1,ui->tableWidget);
}


void travelAgencyUI::on_pushButton_5_clicked()
{
    sort(2,ui->tableWidget);
}





void travelAgencyUI::on_pushButton_6_clicked()
{
    sort(0,ui->tableWidget_2);
}


void travelAgencyUI::on_pushButton_7_clicked()
{
    sort(1,ui->tableWidget_2);
}


void travelAgencyUI::on_pushButton_8_clicked()
{
    sort(2,ui->tableWidget_2);
}

void travelAgencyUI::on_pushButton_9_clicked()
{
    sort(3,ui->tableWidget_2);
}




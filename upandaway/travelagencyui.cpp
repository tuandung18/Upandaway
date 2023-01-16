#include "travelagencyui.h"
#include "BookingsInput.h"
#include "savejson.h"
#include "ui_travelagencyui.h"
#include <flightbooking.h>
#include<rentalcarreservation.h>
#include<hotelbooking.h>
#include<algorithm>
#include<myqtablewidgetitem.h>
#include<qstring.h>
#include <memory>
#include <Algorithmen.h>
#include <heap.h>

#define bType daten[0]
#define bId stoi(daten[1])
#define bPrice stod(daten[2])
#define bFromDate daten[3]
#define bToDate daten[4]
#define bTravelID stol(daten[5])
#define bKundenID stol(daten[6])
#define bKundenName daten[7]
#define loop(size) for(int i{}; i<size; i++)
#define name a[QString("name")].toString()
#define country a[QString("iso_country")].toString()
#define muni a[QString("municipality")].toString()
#define code a[QString("iata_code")].toString()
struct VertexData
{
    int vertexNumber;
    std::string vertexName;
    int endTime;
};
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

void travelAgencyUI::readJsonFile(string sourceName)
{
    QFile file(QString::fromStdString(sourceName));
    file.open (QIODevice::ReadOnly | QIODevice::Text);
    QString json_string;
    json_string = file.readAll();
    file.close();
    auto docu = QJsonDocument::fromJson(json_string.toUtf8());
    for(auto a: docu.array()){

        Airport* airport = new Airport(name,country,muni,code);
        airports.push_back(airport);
        airportMap.insert(code,airport);
    }
}

string travelAgencyUI::readFile(string sourceName)
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



    while(getline(source,line)){
        int numberOfCol = 0;
        lineNumber++;
        vector<string> daten;
        string temp;
        for  (char &ch: line) {
            if(&ch == &line.back()){

                daten.push_back(temp);
                temp.clear();
                numberOfCol++;
                continue;
            }
            if(ch== '|' ){
                daten.push_back(temp);
                temp.clear();
                numberOfCol++;
                continue;
            }
            temp.push_back(ch);

        }

        if(findBooking(bId)==nullptr) //check if booking with this id exists
        {
            string typ =bType;
            int currentIndex = 0;
            if(typ=="F"){

                shared_ptr<Booking> booking =  make_shared<FlightBooking> (bType, bId, bPrice, bFromDate, bToDate, bTravelID,daten[8],daten[9],daten[10]);
                bookings.push_back(booking);
                countF++;
                priceF+=booking->getPrice();
                currentIndex = 10;


            }
            if(typ=="H"){
                shared_ptr<Booking> booking = make_shared<HotelBooking>(bType, bId, bPrice, bFromDate, bToDate, bTravelID,daten[8],daten[9]);
                bookings.push_back(booking);
                countH++;
                priceH+=booking->getPrice();
                currentIndex = 9;
            }
            if(typ=="R"){
                shared_ptr<Booking> booking = make_shared<RentalCarReservation> (bType, bId, bPrice, bFromDate, bToDate, bTravelID, daten[8],daten[9],daten[10]);
                bookings.push_back(booking);
                countR++;
                priceR+=booking->getPrice();
                currentIndex= 10;
            }
            shared_ptr<Booking> nextBooking = bookings.back();


            while(currentIndex != daten.size() -1 ){
                currentIndex++;
                nextBooking->getPreviousBookingsID().push_back(stoi(daten.at(currentIndex)));
            }

            /*
             * Now we check if travelid and customerid
             * already exist
             * */
            if(findTravel(bTravelID)==nullptr)
            {
                shared_ptr <Travel> travel = make_shared<Travel> (bTravelID,bKundenID);
                countTravel++;
                allTravels.push_back(travel);
            }

            findTravel(bTravelID)->addBooking(findBooking(bId));

            if(findCustomer(bKundenID)==nullptr)
            {
               shared_ptr <Customer>customer = make_shared<Customer>(bKundenID,bKundenName);
                countCustomer++;
                allCustomers.push_back(customer);
            }

            findCustomer(bKundenID)->addTravel(findTravel(bTravelID));

        }


    }
    source.close();
    /*
     * create a directed graph for each travel
     * and insert vertices and their edges
     * and perform dfs for the graph
     * */
    vector<VertexData> toBeSorted;
    for(const auto &t : allTravels){

        for(const auto &b : t->getTravelBookings()){
            t->bookingGraph->insertVertex(b->getId(),b);
            for(auto pb : b->getPreviousBookingsID()){
                shared_ptr<Booking> previosBooking = findBooking(pb);
                t->bookingGraph->insertVertex(pb,previosBooking);
                t->bookingGraph->insertEdge(pb,b->getId());
            }

        t->bookingGraph->printAdjMatrix();
        }


        depthFirstSearch(*t->bookingGraph);
        /*
         * set end time after dfs to each booking
         * */
        for(auto b : t->getTravelBookings())
            b->setEndTime(t->bookingGraph->getEnd(b->getId()));
        /*
         * sort the bookings in travelBookings list
         * according to their endtime
         * */
        shared_ptr<Booking> tempSort=nullptr;
        for(int i=0;i<t->getTravelBookings().size();i++){
            for(int j=i+1; j<t->getTravelBookings().size();j++){
                if(t->getTravelBookings().at(j)->getEndTime()<t->getTravelBookings().at(i)->getEndTime()){
                    tempSort = t->getTravelBookings().at(i);
                    t->getTravelBookings().at(i)=t->getTravelBookings().at(j);
                    t->getTravelBookings().at(j)= tempSort;
                }

            }
        }
    }

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

const vector<shared_ptr<Booking> > &travelAgencyUI::getBookings() const
{
    return bookings;
}

void travelAgencyUI::setBookings(const vector<shared_ptr<Booking >> &newBookings)
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

        messageBox->about(this,"Datei erfolgreich eingelesen", QString::fromStdString(readFile(fileName.toStdString())));

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

void travelAgencyUI::saveToJson(){

    if(bookings.empty())
    {
        QMessageBox* message = new QMessageBox;
        message->about(this,QString::fromStdString("No booking"),QString::fromStdString("No booking given"));
        delete message;
    }
    else{QJsonDocument jsonDocument;
        QJsonArray flugBuchung,hotelBuchung,autoBuchung,buchungen;
        QJsonObject list;
        for(auto &b : bookings){
            if(b->getType().back()=='F')
            {
                QJsonObject flight;
                vector<string> detail = b->getDetails();
                flight["airline"] = QString::fromStdString(detail[7]);
                flight["fromDate"] = QString::fromStdString(b->getFromDate());
                flight["fromDest"] = QString::fromStdString(detail[3]);
                flight["id"] = QString::fromStdString(to_string(b->getId()));
                flight["price"] = stoi(detail[8]);
                flight["toDate"] = QString::fromStdString(b->getToDate());
                flight["toDes"] = QString::fromStdString(detail[5]);
                flugBuchung.push_back(flight);
            }
            if(b->getType().back()=='R')
            {
                QJsonObject car;
                vector<string> detail = b->getDetails();
                car["company"] = QString::fromStdString(detail[5]);
                car["fromDate"] = QString::fromStdString(b->getFromDate());
                car["pickupLocation"] = QString::fromStdString(detail[3]);
                car["id"] = QString::fromStdString(to_string(b->getId()));
                car["price"] = stoi(detail[6]);
                car["returnLocation"] = QString::fromStdString(detail[4]);
                car["toDate"] = QString::fromStdString(b->getToDate());
                autoBuchung.push_back(car);

            }
            if(b->getType().back()=='H')
            {
                QJsonObject hotel;
                vector<string> detail = b->getDetails();
                hotel["fromDate"] = QString::fromStdString(b->getFromDate());
                hotel["hotel"] = QString::fromStdString(detail[3]);
                hotel["id"] = QString::fromStdString(to_string(b->getId()));
                hotel["price"] = stoi(detail[5]);
                hotel["toDate"] = QString::fromStdString(b->getToDate());
                hotel["town"] = QString::fromStdString(detail[4]);
                hotelBuchung.push_back(hotel);
            }
        }
        list["Flugbuchungen"] = flugBuchung;

        list["Mietwagenreservierungen"] = autoBuchung;

        list["Hotelbuchungen"] = hotelBuchung;
        buchungen.push_back(list);
        jsonDocument.setArray(buchungen);
        QFileDialog* q = new QFileDialog;
        QString jsonFileName = q->getSaveFileName(this);
        QFile datei(jsonFileName);
        if(!datei.open(QIODevice::ReadWrite))
            std::cerr<<"Datei konnte nicht geoeffnet werden"<<endl;
        else
            cout<<"File opened"<<endl;
        datei.resize(0);
        datei.write(jsonDocument.toJson());
        datei.close();
        delete q;
    }
}
void travelAgencyUI::on_saveData_clicked()
{
}

void travelAgencyUI::setTravelAgency(TravelAgency *newTravelAgency)
{
    travelAgency = newTravelAgency;
}

shared_ptr< Booking>travelAgencyUI::findBooking(long id)
{
    for(auto &b : bookings){
        if(b->getId()==id)
            return b;
    }
    return nullptr;
}

shared_ptr<Travel>travelAgencyUI::findTravel(long id)
{
    for(auto &t : allTravels){
        if(t->getId()==id)
            return t;
    }
    return nullptr;
}

shared_ptr<Customer> travelAgencyUI::findCustomer(long id)
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
    tableWidget->clear();


    idInput*id = new idInput;
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

        shared_ptr<Customer> customer = findCustomer(id->getSavedID());
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

        shared_ptr<Travel> travel = findTravel(travelID.toLong());

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
    QTableWidget* tableWidget5 = ui->tableWidget_5;
    QString bookingID = ui->tableWidget_2->item(row,0)->text();
    shared_ptr<Booking> booking = findBooking(bookingID.toLong());
    if( booking->getType().back()=='R')
    {
        ui->tabWidget->setCurrentIndex(0);
        for(int i = 0; i<tableWidget3->rowCount();i++)
        {

            tableWidget3->setItem(i,0,new MyQTableWidgetItem(QString::fromStdString(booking->getDetails().at(i))));
        }
    }
    if(booking->getType().back()=='F')
    {
        ui->tabWidget->setCurrentIndex(2);
        for(int i = 0; i<tableWidget5->rowCount();i++)
        {

            if(i==4 or i == 6){
                tableWidget5->setItem(i,0,new QTableWidgetItem(airportMap.value(QString::fromStdString(booking->getDetails().at(i-1)))->getAirportName()));
            }
            else{
                tableWidget5->setItem(i,0,new QTableWidgetItem(QString::fromStdString(booking->getDetails().at(i))));
            }
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
    if(ui->tableWidget_5->item(0,0)!=nullptr)
    {
        shared_ptr<Booking> b1 = findBooking(ui->tableWidget_5->item(0,0)->text().toLong());
        if(b1->getType().back()=='F')
        {
            b1->setFromDate(ui->tableWidget_5->item(1,0)->text().toStdString());
            b1->setToDate(ui->tableWidget_5->item(2,0)->text().toStdString());
            auto q1 = airportMap.find(ui->tableWidget_5->item(3,0)->text());
            if(q1!=airportMap.end()){
                b1->setStartAirport(q1.value()->getAirportName());
                b1->setFromDestination(ui->tableWidget_5->item(3,0)->text().toStdString());
                ui->tableWidget_5->setItem(4,0,new MyQTableWidgetItem(q1.value()->getAirportName()));
            }
            else {

                ui->tableWidget_5->setItem(4,0,new MyQTableWidgetItem("Unavailable iata-code"));
                ui->tableWidget_5->item(4,0)->setForeground(QBrush(QColor(255, 0, 0)));
            }
            auto q2 = airportMap.find(ui->tableWidget_5->item(5,0)->text());
            if(q2!=airportMap.end())
                b1->setStartAirport(q2.value()->getAirportName());
            b1->setToDestination(ui->tableWidget_5->item(5,0)->text().toStdString());
            b1->setAirline(ui->tableWidget_5->item(7,0)->text().toStdString());
            b1->setPrice(ui->tableWidget_5->item(8,0)->text().toDouble());

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
        shared_ptr<Booking> b2 = findBooking(ui->tableWidget_4->item(0,0)->text().toLong());
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




void travelAgencyUI::on_readAirport_clicked()
{
    QFileDialog* q = new QFileDialog;
    QString fileName = q->getOpenFileName();
    readJsonFile(fileName.toStdString());

    delete q;
}


void travelAgencyUI::on_saveJsonButton_clicked()
{
    QSharedPointer<SaveJson> jsonPopup(new SaveJson);
    jsonPopup->show();
    jsonPopup->exec();
    SortFunktor sortFunktor = SortFunktor(jsonPopup->getPara());
    std::sort(bookings.begin(),bookings.end(),sortFunktor);
    saveToJson();
}

void travelAgencyUI::on_addCustomer_clicked()
{


        unique_ptr<idInput> customerNameInput = make_unique<idInput>();
        customerNameInput->show();
        customerNameInput->exec();
        for(auto &c : allCustomers){
            if(c->getId()>actualCustomerID)
                actualCustomerID = c->getId();
        }

        /*
         * TODO: Name already exists then add values to the customer not creating new one
         * */

        string customerName = customerNameInput->getSavedCustomerName();
        if(!customerName.empty()){
            actualCustomerID++;
            shared_ptr<Customer> newCustomer = make_shared<Customer>(actualCustomerID,customerName);
            allCustomers.push_back(newCustomer);
        }



}


void travelAgencyUI::on_addBooking_clicked()
{
    /*
     * TODO:
     * 1. Ask for customerID
     * 2. If exists, ask for travelID and ask booking to it
     * 3. If not, just use the last added or actual customerID
     * */

//    idInput customInput;
//    customInput.show();
//    customInput.exec();
//    if(findCustomer(customInput.getSavedID())){
//    }

//    idInput travelInput;
//    travelInput.show();
//    travelInput.exec();
//    travelInput.getSavedID();
    QSharedPointer<BookingsInput> bookingInput(new BookingsInput);
    bookingInput->show();
    bookingInput->exec();


    for(auto &t : allTravels){
        if(t->getId()>actualTravelID)
            actualTravelID=t->getId();
    }
    for(auto &b : bookings){
        if(b->getId()>actualBookingID)
            actualBookingID=b->getId();
    }
    shared_ptr<Travel> newTravel;
    shared_ptr<FlightBooking> newFlight = bookingInput->getNewFlight();
    shared_ptr<RentalCarReservation> newCar = bookingInput->getNewCar();
    shared_ptr<HotelBooking> newHotel = bookingInput->getNewHotel();
    if(newHotel!=nullptr or newCar!=nullptr or newFlight!=nullptr){
        /*
         * Making new travel and booking
         * */
        actualTravelID++;
        actualBookingID++;
        newTravel = make_shared<Travel>(actualTravelID,actualCustomerID);

        findCustomer(actualCustomerID)->addTravel(newTravel);
        allTravels.push_back(newTravel);
        if(newCar!=nullptr){
            newCar->setId(actualBookingID);
            newCar->setTravelID(actualTravelID);


            newTravel->addBooking(newCar);
            bookings.push_back(newCar);

        }
        if(newFlight!=nullptr){
            newFlight->setId(actualBookingID);
            newFlight->setTravelID(actualTravelID);



            newTravel->addBooking(newFlight);

            bookings.push_back(newFlight);

        }
        if(newHotel!=nullptr){
            newHotel->setId(actualBookingID);
            newHotel->setTravelID(actualTravelID);

            newTravel->addBooking(newHotel);

            bookings.push_back(newHotel);

        }

    }


}


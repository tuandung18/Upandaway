#ifndef TRAVELAGENCYUI_H
#define TRAVELAGENCYUI_H
#include "airport.h"
#include "customer.h"
#include <popup.h>
#include <QMainWindow>
#include <vector>
#include <booking.h>
#include<fstream>
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
#include <idinput.h>
#include <QInputDialog>
#include <QListWidget>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include<QTableWidget>
#include<QMap>
#include<flightbooking.h>
using namespace std;
namespace Ui {
class travelAgencyUI;
}

class travelAgencyUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit travelAgencyUI(QWidget *parent = nullptr);
    ~travelAgencyUI();
    void readJsonFile(string sourceName);
    string readFile(string sourceName);
    void readBinaryFile(string sourceName);
    const vector<shared_ptr<Booking>> &getBookings() const;
    void setBookings(const vector<shared_ptr<Booking> > &newBookings);
    void changeWindowName();
    void setTravelAgency(TravelAgency *newTravelAgency);
    shared_ptr<Booking> findBooking(long id);
    shared_ptr<Travel> findTravel(long id);
    shared_ptr<Customer> findCustomer(long id);
    void setAirportName(FlightBooking* f, QMultiMap<QString, Airport *> map);
    int countF=0, countH=0, countR=0, countTravel = 0, countCustomer = 0;
    double priceF=0.0,priceH=0.0,priceR=0.0;
    long actualTravelID=0, actualBookingID = 0;
    long actualCustomerID = 0;






    void sort(int columm, QTableWidget* table);

    void saveToJson();
private slots:
    void on_readFile_clicked();


    void on_showBooking_clicked();

    void on_inputID_clicked();


    void on_showAllBooking_clicked();

    void on_bookings_itemClicked(QListWidgetItem *item);

    void on_saveData_clicked();

    void on_Customer_clicked();



    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_tableWidget_2_cellDoubleClicked(int row, int column);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_readAirport_clicked();

    void on_saveJsonButton_clicked();

    void on_addCustomer_clicked();

    void on_addBooking_clicked();

private:
    Ui::travelAgencyUI *ui;
    vector<Airport*> airports;
    TravelAgency* travelAgency;
    vector<shared_ptr<Booking>> bookings;
    vector<shared_ptr< Customer>> allCustomers;
    vector<shared_ptr<Travel>> allTravels;
    QMultiMap<QString,Airport*> airportMap;
};

#endif // TRAVELAGENCYUI_H

#ifndef TRAVELAGENCYUI_H
#define TRAVELAGENCYUI_H
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
    void readFile(string sourceName);
    string readFile2(string sourceName);
    void readBinaryFile(string sourceName);
    const vector<Booking *> &getBookings() const;
    void setBookings(const vector<Booking *> &newBookings);
    void changeWindowName();
    void setTravelAgency(TravelAgency *newTravelAgency);
    Booking* findBooking (long id);
    Travel* findTravel(long id);
    Customer* findCustomer(long id);




    void sort(int columm, QTableWidget* table);
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

private:
    Ui::travelAgencyUI *ui;
    TravelAgency* travelAgency;
    vector<Booking*> bookings;
    vector<Customer*> allCustomers;
    vector<Travel*> allTravels;
};

#endif // TRAVELAGENCYUI_H

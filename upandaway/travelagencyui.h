#ifndef TRAVELAGENCYUI_H
#define TRAVELAGENCYUI_H
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
private slots:
    void on_readFile_clicked();


    void on_showBooking_clicked();

    void on_inputID_clicked();


    void on_showAllBooking_clicked();

    void on_bookings_itemClicked(QListWidgetItem *item);

    void on_saveData_clicked();

private:
    Ui::travelAgencyUI *ui;
    vector<Booking*> bookings;
};

#endif // TRAVELAGENCYUI_H

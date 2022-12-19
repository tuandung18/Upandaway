#include "BookingsInput.h"
#include "flightbooking.h"
#include "ui_bookingchoices.h"
#include <QString>
#include <iostream>
#define flightFromDate ui->tableWidget_5->item(1,0)->text().toStdString()
#define flightToDate ui->tableWidget_5->item(2,0)->text().toStdString()
#define flightFromLoc ui->tableWidget_5->item(3,0)->text().toStdString()
#define flightToLoc ui->tableWidget_5->item(4,0)->text().toStdString()
#define flightCompany ui->tableWidget_5->item(5,0)->text().toStdString()
#define flightPrice ui->tableWidget_5->item(6,0)->text().toStdString()

#define hotelFromDate ui->tableWidget_4->item(1,0)->text().toStdString()
#define hotelToDate ui->tableWidget_4->item(2,0)->text().toStdString()
#define hotelName ui->tableWidget_4->item(3,0)->text().toStdString()
#define hotelTown ui->tableWidget_4->item(4,0)->text().toStdString()
#define hotelPrice ui->tableWidget_4->item(5,0)->text().toStdString()

#define carStartDate ui->tableWidget_3->item(1,0)->text().toStdString()
#define carToDate ui->tableWidget_3->item(2,0)->text().toStdString()
#define carStartLoc ui->tableWidget_3->item(3,0)->text().toStdString()
#define carToLoc ui->tableWidget_3->item(4,0)->text().toStdString()
#define carCompany ui->tableWidget_3->item(5,0)->text().toStdString()
#define carPrice ui->tableWidget_3->item(6,0)->text().toStdString()


BookingsInput::BookingsInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bookingchoices)
{
    ui->setupUi(this);
}

BookingsInput::~BookingsInput()
{
    delete ui;
}



void BookingsInput::on_pushButton_clicked()
{
    /*
     *  TODO: Try catch to secure errors by inputs.
     *  If you press the button without
     *  typing the inputs, it may still
     *  work but give empty strings
     */


    if(ui->tabWidget->currentIndex()==2){
        try{

            setNewFlight( std::make_shared<FlightBooking>("F",0, stod(flightPrice),flightFromDate,flightToDate,0,flightFromLoc,flightToLoc,flightCompany));
        }catch(exception &e){
            cerr<<"SIGSEGV caught"<<endl;
            setNewFlight(nullptr);
        }

    }
    if(ui->tabWidget->currentIndex()==1){
        try{
            setNewHotel(make_shared<HotelBooking>("H",0,stod(hotelPrice),hotelFromDate,hotelToDate,0,hotelName,hotelTown));

        }catch(exception &e){
            cerr<<"SIGSEGV caught"<<endl;
            setNewFlight(nullptr);
        }

    }

    else {
        try{
            setNewCar(make_shared<RentalCarReservation>("R",0,stod(carPrice),carStartDate,carToDate,0,carStartLoc,carToLoc,carCompany));
        }catch(exception &e){
            cerr<<"SIGSEGV caught"<<endl;
            setNewFlight(nullptr);
        }
    }
    close();
}

std::shared_ptr<RentalCarReservation> BookingsInput::getNewCar() const
{
    return newCar;
}

void BookingsInput::setNewCar(const std::shared_ptr<RentalCarReservation> &newNewCar)
{
    newCar = newNewCar;
}

std::shared_ptr<HotelBooking> BookingsInput::getNewHotel() const
{
    return newHotel;
}

void BookingsInput::setNewHotel(const std::shared_ptr<HotelBooking> &newNewHotel)
{
    newHotel = newNewHotel;
}

std::shared_ptr<FlightBooking> BookingsInput::getNewFlight() const
{
    return newFlight;
}

void BookingsInput::setNewFlight(const std::shared_ptr<FlightBooking> &newNewFlight)
{
    newFlight = newNewFlight;
}


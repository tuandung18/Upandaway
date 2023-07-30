#ifndef BOOKINGSINPUT_H
#define BOOKINGSINPUT_H

#include "flightbooking.h"
#include "rentalcarreservation.h"
#include "hotelbooking.h"
#include <QDialog>

namespace Ui {
class BookingsInput;
}

class BookingsInput : public QDialog
{
    Q_OBJECT

public:
    explicit BookingsInput(QWidget *parent = nullptr);
    ~BookingsInput();

    std::shared_ptr<FlightBooking> getNewFlight() const;
    void setNewFlight(const std::shared_ptr<FlightBooking> &newNewFlight);

    std::shared_ptr<RentalCarReservation> getNewCar() const;
    void setNewCar(const std::shared_ptr<RentalCarReservation> &newNewCar);
    std::shared_ptr<HotelBooking> getNewHotel() const;
    void setNewHotel(const std::shared_ptr<HotelBooking> &newNewHotel);

private slots:

    void on_pushButton_clicked();

private:
    Ui::BookingsInput *ui;
    std::shared_ptr<FlightBooking> newFlight;
    std::shared_ptr<RentalCarReservation> newCar;
    std::shared_ptr<HotelBooking> newHotel;
};

#endif // BOOKINGSINPUT_H

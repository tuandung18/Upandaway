#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H

#include "booking.h"

class RentalCarReservation : public Booking
{
private:
    string pickupLocation;
    string returnLocation;
    string company;
public:

    RentalCarReservation();
    RentalCarReservation(const string &pickupLocation, const string &returnLocation, const string &company);
    string showDetails() override;
    std::vector<string> getDetails() override;

};

#endif // RENTALCARRESERVATION_H

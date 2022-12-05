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

    string getPickupLocation() const;
    void setPickupLocation(const string &newPickupLocation) override;
    string getReturnLocation() const;
    void setReturnLocation(const string &newReturnLocation) override;
    string getCompany() const;
    void setCompany(const string &newCompany) override;
};

#endif // RENTALCARRESERVATION_H

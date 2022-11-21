#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H

#include "booking.h"

class HotelBooking : public Booking
{
private:
    string hotel;
    string town;

public:
    HotelBooking();
    HotelBooking(const string &hotel, const string &town);
    string showDetails() override;
    std::vector<string> getDetails() override;

};

#endif // HOTELBOOKING_H

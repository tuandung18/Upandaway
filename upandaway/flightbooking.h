#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H

#include "booking.h"

class FlightBooking : public Booking
{
private:
    string fromDestination;
    string toDestination;
    string airline;
public:
    FlightBooking();
    FlightBooking(const string &fromDestination, const string &toDestination, const string &airline);
    FlightBooking(char fromDestination[], char toDestination[], char airline[]);

    string showDetails() override;


    // Booking interface
    public:
        std::vector<string> getDetails() override;
};

#endif // FLIGHTBOOKING_H

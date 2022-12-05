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
    string getFromDestination() const;
    void setFromDestination(const string &newFromDestination) override;
    string getToDestination() const;
    void setToDestination(const string &newToDestination) override;
    string getAirline() const;
    void setAirline(const string &newAirline) override;
};

#endif // FLIGHTBOOKING_H

#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H

#include "booking.h"

class FlightBooking : public Booking
{
private:
    string fromDestination;
    string startAirport;
    string toDestination;
    string endAirport;
    string airline;
public:
    FlightBooking();
    FlightBooking(const string &fromDestination, const string &toDestination, const string &airline);
    FlightBooking(string type, int id, double price, string fromDate, string toDate, long travelID, const string &fromDestination, const string &toDestination, const string &airline);

    FlightBooking(char fromDestination[], char toDestination[], char airline[]);

    string showDetails() override;


    // Booking interface
    public:
    std::vector<string> getDetails() override;
    string getFromDestination() const override;
    void setFromDestination(const string &newFromDestination) override;
    string getToDestination() const override;
    void setToDestination(const string &newToDestination) override;
    string getAirline() const;
    void setAirline(const string &newAirline) override;
    string getStartAirport() const;
    void setStartAirport(const QString &newStartAirport) override;
    string getEndAirport() const;
    void setEndAirport(const QString &newEndAirport) override;
};

#endif // FLIGHTBOOKING_H

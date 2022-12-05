#include "flightbooking.h"

string FlightBooking::getFromDestination() const
{
    return fromDestination;
}

void FlightBooking::setFromDestination(const string &newFromDestination)
{
    fromDestination = newFromDestination;
}

string FlightBooking::getToDestination() const
{
    return toDestination;
}

void FlightBooking::setToDestination(const string &newToDestination)
{
    toDestination = newToDestination;
}

string FlightBooking::getAirline() const
{
    return airline;
}

void FlightBooking::setAirline(const string &newAirline)
{
    airline = newAirline;
}

FlightBooking::FlightBooking()
{

}

string FlightBooking::showDetails()
{
    string stringID = to_string(id);
    string stringPreis = to_string(price);
    string mes = "Flugbuchung " + stringID + " von " + fromDestination + " nach " + toDestination + " mit " + airline + " am " + fromDate + ". Preis: " + stringPreis + " Euro";
    return mes;
}

std::vector<string> FlightBooking::getDetails()
{
    vector<string> result;
    result.push_back(to_string(id));
    result.push_back(fromDate);
    result.push_back(toDate);
    result.push_back(fromDestination);
    result.push_back(toDestination);
    result.push_back(airline);
    result.push_back(to_string(price));
    return result;
}

FlightBooking::FlightBooking(const string &fromDestination, const string &toDestination, const string &airline)
    : Booking(0, 0.0, "", "" ),
    fromDestination(fromDestination),
    toDestination(toDestination),
    airline(airline)
{}
FlightBooking::FlightBooking( char fromDestination[], char toDestination[], char airline[])
    : Booking(0, 0.0, "", "" ),
    fromDestination(string(fromDestination, fromDestination+3)),
    toDestination(string(toDestination,toDestination+3)),
    airline(string(airline,airline+15))
{}

#include "flightbooking.h"

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

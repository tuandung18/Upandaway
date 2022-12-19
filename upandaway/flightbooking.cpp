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

string FlightBooking::getStartAirport() const
{
    return startAirport;
}

void FlightBooking::setStartAirport(const QString &newStartAirport)
{
    startAirport = newStartAirport.toStdString();
}

string FlightBooking::getEndAirport() const
{
    return endAirport;
}

void FlightBooking::setEndAirport(const QString &newEndAirport)
{
    endAirport = newEndAirport.toStdString();
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
    result.push_back(startAirport="startap");
    result.push_back(toDestination);
    result.push_back(endAirport="endep");
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

FlightBooking::FlightBooking(string type, int id, double price, string fromDate, string toDate, long travelID, const string &fromDestination, const string &toDestination, const string &airline)

    : Booking(type, id, price, fromDate, toDate, travelID ),
      fromDestination(fromDestination),
      toDestination(toDestination),
      airline(airline)
{
    if(fromDestination.size()!=3 || toDestination.size()!=3)
        throw invalid_argument("Wrong airport names");

    string tempPrice = to_string((int)price);
    auto it = tempPrice.begin();/* this block is to check double type*/
    while (it != tempPrice.end() && (std::isdigit(*it) || *it == '.')) {
        it++;
    }
    if(tempPrice.empty() || it != tempPrice.end())
        throw invalid_argument("Wrong price type");
}
FlightBooking::FlightBooking( char fromDestination[], char toDestination[], char airline[])
    : Booking(0, 0.0, "", "" ),
    fromDestination(string(fromDestination, fromDestination+3)),
    toDestination(string(toDestination,toDestination+3)),
    airline(string(airline,airline+15))
{}

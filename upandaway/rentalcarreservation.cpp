#include "rentalcarreservation.h"

string RentalCarReservation::getPickupLocation() const
{
    return pickupLocation;
}

void RentalCarReservation::setPickupLocation(const string &newPickupLocation)
{
    pickupLocation = newPickupLocation;
}

string RentalCarReservation::getReturnLocation() const
{
    return returnLocation;
}

void RentalCarReservation::setReturnLocation(const string &newReturnLocation)
{
    returnLocation = newReturnLocation;
}

string RentalCarReservation::getCompany() const
{
    return company;
}

void RentalCarReservation::setCompany(const string &newCompany)
{
    company = newCompany;
}

RentalCarReservation::RentalCarReservation()
{

}

string RentalCarReservation::showDetails()
{
    string stringID = to_string(id);
    string stringPreis = to_string(price);
    string mes = "Mietwagenreservierung " + stringID + " mit " + company + ". Abholung am " + fromDate + " in " + pickupLocation + ". Rückgabe am " + toDate + "in" + returnLocation + ". Preis: " + stringPreis;
    return mes;
}

std::vector<string> RentalCarReservation::getDetails()
{
    vector<string> result;
    result.push_back(to_string(id));
    result.push_back(fromDate);
    result.push_back(toDate);
    result.push_back(pickupLocation);
    result.push_back(returnLocation);
    result.push_back(company);
    result.push_back(to_string(price));
    return result;
}

RentalCarReservation::RentalCarReservation(const string &pickupLocation, const string &returnLocation, const string &company)
    : Booking(0, 0.0, "", "" ),
      pickupLocation(pickupLocation),
      returnLocation(returnLocation),
      company(company)
{}

RentalCarReservation::RentalCarReservation(string type, int id, double price, string fromDate, string toDate, long travelID, const string &pickupLocation, const string &returnLocation, const string &company):
    Booking(type, id, price, fromDate, toDate, travelID ),
    pickupLocation(pickupLocation),
    returnLocation(returnLocation),
    company(company)

{}

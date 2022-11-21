#include "rentalcarreservation.h"

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

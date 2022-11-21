#include "hotelbooking.h"

HotelBooking::HotelBooking()
{

}

string HotelBooking::showDetails()
{
    string stringID = to_string(id);
    string stringPreis = to_string(price);
    string mes = "Hotelreservierung " + stringID + " im " + hotel + " in " + town + " vom " +  fromDate +  " bis zum " + toDate + ". Preis: " + stringPreis + " Euro";
    return mes;
}

std::vector<string> HotelBooking::getDetails()
{
    vector<string> result;
    result.push_back(hotel);
    result.push_back(town);
    result.push_back(to_string(price));
    return result;
}

HotelBooking::HotelBooking(const string &hotel, const string &town)
    : Booking(0, 0.0, "", "" ),
      hotel(hotel),
      town(town)
{}

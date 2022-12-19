#include "hotelbooking.h"

string HotelBooking::getHotel() const
{
    return hotel;
}

void HotelBooking::setHotel(const string &newHotel)
{
    hotel = newHotel;
}

string HotelBooking::getTown() const
{
    return town;
}

void HotelBooking::setTown(const string &newTown)
{
    town = newTown;
}

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
    result.push_back(to_string(id));
    result.push_back(fromDate);
    result.push_back(toDate);
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

HotelBooking::HotelBooking(string type, int id, double price, string fromDate, string toDate, long travelID, const string &hotel, const string &town) :
    Booking(type, id, price, fromDate, toDate, travelID ),
    hotel(hotel),
    town(town)
{}

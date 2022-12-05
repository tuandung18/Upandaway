#include "travel.h"

long Travel::getCustomerId() const
{
    return customerId;
}

void Travel::setCustomerId(long newCustomerId)
{
    customerId = newCustomerId;
}

long Travel::getId() const
{
    return id;
}

void Travel::setId(long newId)
{
    id = newId;
}

vector<Booking *> Travel::getTravelBookings() const
{
    return travelBookings;
}

void Travel::setTravelBookings(const vector<Booking *> &newTravelBookings)
{
    travelBookings = newTravelBookings;
}

Travel::Travel(long id, long customerId)
    : id(id), customerId(customerId)
{

}
bool Travel::searchBooking(long id)
{
    for(auto &t : travelBookings){
        if(t->getId()==id)
            return true;
    }
    return false;
}
Booking* Travel::soonestBooking()
{
    Booking* soonestDBooking = travelBookings.front();
    for(auto &b : travelBookings)
    {
        if(stoi(b->getFromDate())<stoi(soonestDBooking->getFromDate()))
            soonestDBooking = b;
    }
    return soonestDBooking;
}
Booking* Travel::latestBooking()
{
    Booking* latestBooking = travelBookings.front();
    for(auto &b : travelBookings)
    {
        if(stoi(b->getToDate())>stoi(latestBooking->getToDate()))
            latestBooking = b;
    }
    return latestBooking;
}
void Travel::addBooking(Booking *booking)
{
    if(!searchBooking(booking->getId()))
        travelBookings.push_back(booking);
}

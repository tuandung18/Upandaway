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

vector<shared_ptr<Booking>> Travel::getTravelBookings() const
{
    return travelBookings;
}

void Travel::setTravelBookings(const vector<shared_ptr<Booking>> &newTravelBookings)
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
shared_ptr<Booking> Travel::soonestBooking()
{
    shared_ptr<Booking> soonestDBooking = travelBookings.front();
    for(auto &b : travelBookings)
    {
        if(stoi(b->getFromDate())<stoi(soonestDBooking->getFromDate()))
            soonestDBooking = b;
    }
    return soonestDBooking;
}
shared_ptr<Booking>Travel::latestBooking()
{
    shared_ptr<Booking> latestBooking = travelBookings.front();
    for(auto &b : travelBookings)
    {
        if(stoi(b->getToDate())>stoi(latestBooking->getToDate()))
            latestBooking = b;
    }
    return latestBooking;
}
void Travel::addBooking(shared_ptr<Booking>booking)
{
    if(!searchBooking(booking->getId()))
        travelBookings.push_back(booking);
}

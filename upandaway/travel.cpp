#include "travel.h"
#include "flightbooking.h"

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

vector<shared_ptr<Booking>>* Travel::getTravelBookings() const
{
    return travelBookings;
}



Travel::Travel(long id, long customerId)
    : id(id), customerId(customerId)
{

}
bool Travel::searchBooking(long id)
{
    for(auto &t : *travelBookings){
        if(t->getId()==id)
            return true;
    }
    return false;
}
shared_ptr<Booking> Travel::soonestBooking()
{
    shared_ptr<Booking> soonestDBooking = travelBookings->front();
    for(auto &b : *travelBookings)
    {
        if(stoi(b->getFromDate())<stoi(soonestDBooking->getFromDate()))
            soonestDBooking = b;
    }
    return soonestDBooking;
}
shared_ptr<Booking>Travel::latestBooking()
{
    shared_ptr<Booking> latestBooking = travelBookings->front();
    for(auto &b : *travelBookings)
    {
        if(stoi(b->getToDate())>stoi(latestBooking->getToDate()))
            latestBooking = b;
    }
    return latestBooking;
}

bool Travel::checkRoundTrip()
{
    shared_ptr<Booking> start=nullptr;
    shared_ptr<Booking>end;
    for(const auto &b: *travelBookings){
        if(b->getType()=="F"){
            if(start==nullptr)
                start= b;
            end = b;
        }
    }

    if(start->getFromDestination()==end->getToDestination())
        return true;
    return false;
}

bool Travel::checkEnoughHotels()
{
    shared_ptr<Booking> start=nullptr;
    shared_ptr<Booking>end;
    shared_ptr<Booking> currHotel;
    for(auto b: *getTravelBookings()){
        if(b->getType()!="R"){
            if(b->getType()=="H")
               currHotel=b;

            if(b->getType()=="F"){
                if(start==nullptr)
                    start = b;
                else{
                    end = b;
                    if(currHotel!=nullptr){
                        if(end->getFromDate()!=start->getToDate()){
                            if((stoi(currHotel->getFromDate()) != stoi(start->getToDate()))
                                    or (stoi(currHotel->getToDate()) != stoi(end->getFromDate())))
                                return false;
                        }
                        start = end;
                    }
                }

            }
        }
    }
    return true;
}

bool Travel::checkNoUselessHotel()
{
    shared_ptr<Booking> start=nullptr;
    shared_ptr<Booking>end;
    shared_ptr<Booking> currHotel;
    for(auto b: *getTravelBookings()){
        if(b->getType()!="R"){
            if(b->getType()=="H")
                currHotel=b;

            if(b->getType()=="F"){
                if(start==nullptr)
                    start = b;
                else{
                    end = b;
                    if(currHotel!=nullptr){
                        if(currHotel->getFromDate()<start->getToDate()
                                or currHotel->getToDate()>end->getFromDate())
                            return false;

                        start = end;
                    }
                }

            }
        }
    }
    return true;
}

bool Travel::checkNoUselessRentalCars()
{

    shared_ptr<Booking> start=nullptr;
    shared_ptr<Booking>end;
    shared_ptr<Booking> currRentalCar;
    for(auto b: *getTravelBookings()){
        if(b->getType()!="H"){
            if(b->getType()=="R")
                currRentalCar=b;

            if(b->getType()=="F"){
                if(start==nullptr)
                    start = b;
                else{
                    end = b;
                    if(currRentalCar!=nullptr){
                        if(currRentalCar->getFromDate()<start->getToDate()
                            or currRentalCar->getToDate()>end->getFromDate())
                        return false;
                        start = end;
                    }

                }

            }
        }
    }
    return true;

}
void Travel::addBooking(shared_ptr<Booking>booking)
{
    if(!searchBooking(booking->getId()))
        travelBookings->push_back(booking);
}

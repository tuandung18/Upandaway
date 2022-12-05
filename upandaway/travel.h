#ifndef TRAVEL_H
#define TRAVEL_H


#include "booking.h"
class Travel
{
private:
    long id, customerId;
    vector<Booking*> travelBookings;
public:
    Travel(long id, long customerId);
    void addBooking(Booking* booking);
    long getCustomerId() const;
    void setCustomerId(long newCustomerId);
    long getId() const;
    void setId(long newId);
    vector<Booking *> getTravelBookings() const;
    void setTravelBookings(const vector<Booking *> &newTravelBookings);
    bool searchBooking(long id);

    Booking *soonestBooking();
    Booking *latestBooking();
};

#endif // TRAVEL_H

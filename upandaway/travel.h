#ifndef TRAVEL_H
#define TRAVEL_H
#include <memory>

#include "booking.h"
class Travel
{
private:
    long id, customerId;
    vector<shared_ptr<Booking>> travelBookings;
public:
    Travel(long id, long customerId);
    void addBooking(shared_ptr<Booking> booking);
    long getCustomerId() const;
    void setCustomerId(long newCustomerId);
    long getId() const;
    void setId(long newId);
    vector<shared_ptr<Booking> > getTravelBookings() const;
    void setTravelBookings(const vector<shared_ptr<Booking> > &newTravelBookings);
    bool searchBooking(long id);

    shared_ptr<Booking>soonestBooking();
    shared_ptr<Booking>latestBooking();
};

#endif // TRAVEL_H

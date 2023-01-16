#ifndef TRAVEL_H
#define TRAVEL_H
#include <memory>
#include <graph.h>
#include "booking.h"
#include <Algorithmen.h>
class Travel
{
private:
    long id, customerId;
    vector<shared_ptr<Booking>>* travelBookings = new vector<shared_ptr<Booking>>;
public:
    Travel(long id, long customerId);
    void addBooking(shared_ptr<Booking> booking);
    long getCustomerId() const;
    void setCustomerId(long newCustomerId);
    long getId() const;
    void setId(long newId);
    vector<shared_ptr<Booking> > *getTravelBookings() const;
    void setTravelBookings(const vector<shared_ptr<Booking> > &newTravelBookings);
    bool searchBooking(long id);

    shared_ptr<Booking>soonestBooking();
    shared_ptr<Booking>latestBooking();

    Graph<shared_ptr<Booking>,110>* bookingGraph = new Graph<shared_ptr<Booking>,110>;

    bool checkRoundTrip();
    bool checkEnoughHotels();
    bool checkNoUselessHotel();
    bool checkNoUselessRentalCars();
};

#endif // TRAVEL_H

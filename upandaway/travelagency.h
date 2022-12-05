#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H
#include <vector>
#include <booking.h>
#include<fstream>
using namespace std;
class TravelAgency
{
private:
    vector<Booking*> bookings;
public:
    TravelAgency();
    void readFile(string sourceName);
    void readBinaryFile(string sourceName);
    const vector<Booking *> &getBookings() const;
    void setBookings(const vector<Booking *> &newBookings);
    string readFile2(string sourceName);
};

#endif // TRAVELAGENCY_H

#ifndef BOOKING_H
#define BOOKING_H
#include <string>
#include <QDate>
#include <QDateEdit>
using namespace std;

class Booking
{
protected:
    string type;
    long id;
    long travelID;
    double price;
    string fromDate;
    string toDate;
public:
    Booking();
    Booking(int id, double price, const string &fromDate, const string &toDate);
    Booking(const string &type,int id, double price, const string &fromDate, const string &toDate, long travelID);

    virtual string showDetails() = 0;
    virtual vector<string> getDetails() = 0;
    virtual void setFromDestination(const string &newFromDestination);
    virtual void setToDestination(const string &newToDestination) ;
    virtual void setAirline(const string &newAirline) ;

    virtual void setReturnLocation(const string &newReturnLocation);
    virtual void setPickupLocation(const string &newPickupLocation);
    virtual void setCompany(const string &newCompany);

    virtual void setHotel(const string &newHotel);

    virtual void setTown(const string &newTown);
    virtual void setStartAirport(const QString &newStartAirport);
    virtual void setEndAirport(const QString &newEndAirport);



    long getId() const;
    void setId(long newId);
    double getPrice() const;
    void setPrice(double newPrice);
    const string &getFromDate() const;
    void setFromDate(const string &newFromDate);
    const string &getToDate() const;
    void setToDate(const string &newToDate);
    QDate setQDate(const string &date);
    QDateEdit fixQDate(const QDate &qdate);
    virtual ~Booking();
    const string &getType() const;
    void setType(const string &newType);
    long getTravelID() const;
    void setTravelID(long newTravelID);
};

#endif // BOOKING_H

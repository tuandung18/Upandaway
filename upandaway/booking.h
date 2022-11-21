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
    double price;
    string fromDate;
    string toDate;
public:
    Booking();
    Booking(int id, double price, const string &fromDate, const string &toDate);
    virtual string showDetails() = 0;
    virtual vector<string> getDetails() = 0;
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
};

#endif // BOOKING_H

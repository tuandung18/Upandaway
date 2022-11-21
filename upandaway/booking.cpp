#include "booking.h"

long Booking::getId() const
{
    return id;
}

void Booking::setId(long newId)
{
    id = newId;
}

double Booking::getPrice() const
{
    return price;
}

void Booking::setPrice(double newPrice)
{
    price = newPrice;
}

const string &Booking::getFromDate() const
{
    return fromDate;
}

void Booking::setFromDate(const string &newFromDate)
{
    fromDate = newFromDate;
}

const string &Booking::getToDate() const
{
    return toDate;
}

void Booking::setToDate(const string &newToDate)
{
    toDate = newToDate;
}

QDate Booking::setQDate(const string &date)
{
    return QDate::fromString(QString::fromStdString(date),"yyyyMMdd");
}



Booking::~Booking()
{

}

const string &Booking::getType() const
{
    return type;
}

void Booking::setType(const string &newType)
{
    type = newType;
}

Booking::Booking()
{

}

Booking::Booking(int id, double price, const string &fromDate, const string &toDate) : id(id),
    price(price),
    fromDate(fromDate),
    toDate(toDate)
{}

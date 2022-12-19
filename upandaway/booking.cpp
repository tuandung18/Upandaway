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

QDateEdit Booking::fixQDate(const QDate &qdate)
{

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

long Booking::getTravelID() const
{
    return travelID;
}

void Booking::setTravelID(long newTravelID)
{
    travelID = newTravelID;
}

Booking::Booking()
{

}

Booking::Booking(int id, double price, const string &fromDate, const string &toDate) :

    id(id),
    price(price),
    fromDate(fromDate),
    toDate(toDate)
{}

Booking::Booking(const string &type, int id, double price, const string &fromDate, const string &toDate, long travelID) :
    type(type),
    id(id),
    travelID(travelID),
    price(price),
    fromDate(fromDate),
    toDate(toDate)


{

}

void Booking::setFromDestination(const string &newFromDestination)
{

}

void Booking::setToDestination(const string &newToDestination)
{

}

void Booking::setAirline(const string &newAirline)
{

}

void Booking::setReturnLocation(const string &newReturnLocation)
{

}

void Booking::setPickupLocation(const string &newPickupLocation)
{

}

void Booking::setCompany(const string &newCompany)
{

}

void Booking::setHotel(const string &newHotel)
{

}

void Booking::setTown(const string &newTown)
{

}

void Booking::setStartAirport(const QString &newStartAirport)
{

}

void Booking::setEndAirport(const QString &newEndAirport)
{

}

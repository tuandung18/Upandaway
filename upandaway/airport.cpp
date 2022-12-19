#include "airport.h"

Airport::Airport(QString name, QString iso_country, QString municipality, QString iata_code):
    airportName(name),
    iso_country(iso_country),
    municipality(municipality),
    iata_code(iata_code)
{

}

QString Airport::getAirportName() const
{
    return airportName;
}

void Airport::setAirportName(const QString &newAirportName)
{
    airportName = newAirportName;
}

QString Airport::getIso_country() const
{
    return iso_country;
}

void Airport::setIso_country(const QString &newIso_country)
{
    iso_country = newIso_country;
}

QString Airport::getMunicipality() const
{
    return municipality;
}

void Airport::setMunicipality(const QString &newMunicipality)
{
    municipality = newMunicipality;
}

QString Airport::getIata_code() const
{
    return iata_code;
}

void Airport::setIata_code(const QString &newIata_code)
{
    iata_code = newIata_code;
}

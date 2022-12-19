#ifndef AIRPORT_H
#define AIRPORT_H
#include<qstring.h>
#include <string>
using namespace std;

class Airport
{
public:
    Airport(QString name, QString iso_country, QString municipality, QString iata_code);
    QString getAirportName() const;
    void setAirportName(const QString &newAirportName);
    QString getIso_country() const;
    void setIso_country(const QString &newIso_country);
    QString getMunicipality() const;
    void setMunicipality(const QString &newMunicipality);
    QString getIata_code() const;
    void setIata_code(const QString &newIata_code);

private:

    QString airportName;
    QString iso_country;
    QString municipality;
    QString iata_code;
};

#endif // AIRPORT_H

#ifndef CUSTOMER_H
#define CUSTOMER_H


#include "travel.h"
class Customer
{
private:
    long id;
    string name;
    vector<Travel* > travelList;
public:
    Customer(long id, string name);
    void addTravel(Travel* travel);
    long getId() const;
    void setId(long newId);
    string getName() const;
    void setName(const string &newName);
    vector<Travel *> getTravelList() const;
    void setTravelList(const vector<Travel *> &newTravelList);
    bool searchTravel(long id);
};

#endif // CUSTOMER_H

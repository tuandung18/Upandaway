#ifndef CUSTOMER_H
#define CUSTOMER_H


#include "travel.h"
class Customer
{
private:
    long id;
    string name;
    vector<shared_ptr<Travel> > travelList;
public:
    double relaDistance;
    Customer(long id, string name);
    void addTravel(shared_ptr<Travel> travel);
    long getId() const;
    void setId(long newId);
    string getName() const;
    void setName(const string &newName);
    vector<shared_ptr<Travel>> getTravelList() const;
    void setTravelList(const vector<shared_ptr<Travel>> &newTravelList);
    bool searchTravel(long id);
};

#endif // CUSTOMER_H

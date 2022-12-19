#include "customer.h"
#include <iostream>
#include <ostream>

long Customer::getId() const
{
    return id;
}

void Customer::setId(long newId)
{
    id = newId;
}

string Customer::getName() const
{
    return name;
}

void Customer::setName(const string &newName)
{
    name = newName;
}

vector<shared_ptr<Travel>> Customer::getTravelList() const
{
    return travelList;
}

void Customer::setTravelList(const vector<shared_ptr<Travel>> &newTravelList)
{
    travelList = newTravelList;
}

Customer::Customer(long id, string name)
    : id(id), name(name)
{

}
bool Customer::searchTravel(long id)
{
    for(auto &t : travelList){
        if(t->getId()==id)
            return true;
    }
    return false;
}
void Customer::addTravel(shared_ptr<Travel>travel)
{
    if(travelList.empty())
        travelList.push_back(travel);
    else if(!searchTravel(travel->getId()))
        travelList.push_back(travel);

}

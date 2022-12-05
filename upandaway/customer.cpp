#include "customer.h"

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

vector<Travel *> Customer::getTravelList() const
{
    return travelList;
}

void Customer::setTravelList(const vector<Travel *> &newTravelList)
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
void Customer::addTravel(Travel *travel)
{
    if(!searchTravel(travel->getId()))
        travelList.push_back(travel);

}

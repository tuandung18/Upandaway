
#include "sortfunktor.h"

SortFunktor::SortFunktor(SortFunktor::SortierParameter parameter):sortierParameter(parameter)
{

}

bool SortFunktor::operator()(shared_ptr<Booking> booking1, shared_ptr<Booking> booking2){
    if (sortierParameter == PRICE)
        return booking1->getPrice() < booking2->getPrice();
    else if (sortierParameter == ID)
        return booking1->getId() < booking2->getId();
    else if (sortierParameter == FROMDATE)
        return booking1->getFromDate() < booking2->getFromDate();
    else if(sortierParameter == TODATE)
        return booking1->getToDate() < booking2->getToDate();
    else
        return false;
}

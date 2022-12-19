#ifndef SORTFUNKTOR_H
#define SORTFUNKTOR_H
#include <algorithm>
#include <booking.h>
class SortFunktor
{
public:
    enum SortierParameter{
        ID=0, PRICE=1, FROMDATE=2, TODATE=3
    };
    SortFunktor(SortFunktor::SortierParameter parameter = ID);
    bool operator()(shared_ptr<Booking> booking1, shared_ptr<Booking> booking2);
private:
   SortFunktor::SortierParameter sortierParameter = ID;
};
#endif // SORTFUNKTOR_H

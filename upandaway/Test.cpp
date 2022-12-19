#include "Test.h"

void Test::test_case1()
{

    travelAgencyUI* d = new travelAgencyUI;

    d->readFile("/home/tuandl/git/Mo56y-1-Le/upandaway/bookings2.txt");
    int countAvis=0, countUA = 0, count1k = 0;
    for(shared_ptr<Booking> b : d->getBookings()){

        if(b->getType()=="R")
        {
            if(b->getDetails().at(5)=="Avis\r"){
                countAvis++;
            }
        }
        if (b->getType()=="F") {
            if(b->getDetails().at(7)=="United Airlines\r")
                countUA++;
        }
        if(b->getPrice()>=1000.0)
            count1k++;
    }
    QCOMPARE(countAvis,5);
    QCOMPARE(countUA,3);
    QCOMPARE(count1k,31);

}

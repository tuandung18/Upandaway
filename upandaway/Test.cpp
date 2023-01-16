#include "Test.h"

void Test::test_case1()
{

    travelAgencyUI* d = new travelAgencyUI;

    d->readFile("/home/tuandl/git/Mo56y-1-Le/upandaway/bookings5.txt");
    shared_ptr<Travel> testTravel = d->findTravel(8);
    QCOMPARE(testTravel->checkEnoughHotels(),false);

}

#include <QtTest>
#include <QCoreApplication>
#include <memory>
// add necessary includes here
#include <travelagencyui.h>
#include <QObject>
#include <QApplication>
#include <flightbooking.h>
#include<rentalcarreservation.h>
#include<hotelbooking.h>

class MyTestCase : public QObject
{
    Q_OBJECT

public:
    MyTestCase();
    ~MyTestCase();

private slots:
    void test_case1();

};

MyTestCase::MyTestCase()
{

}

MyTestCase::~MyTestCase()
{

}

void MyTestCase::test_case1()
{

    travelAgencyUI* d = new travelAgencyUI;

    d->readFile("/home/tuandl/git/Mo56y-1-Le/upandaway/booking2.txt");
    int countAvis=0;
    for(shared_ptr<Booking> b : d->getBookings()){

        if(b->getType()=="F")
        {
            if(b->getDetails()[7]=="Avis"){
                countAvis++;
            }
        }

    }
    QCOMPARE(countAvis,5);

}

QTEST_MAIN(MyTestCase)

#include "tst_mytestcase.moc"

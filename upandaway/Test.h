#ifndef TEST_H
#define TEST_H
#include <QtTest/QTest>
#include <QCoreApplication>
#include <memory>
// add necessary includes here
#include <travelagencyui.h>
#include <QObject>
#include <QApplication>
#include <flightbooking.h>
#include<rentalcarreservation.h>
#include<hotelbooking.h>

class Test : public QObject
{
    Q_OBJECT



private slots:
    void test_case1();

};









#endif // TEST_H

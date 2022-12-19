QT       += core gui
QT       += testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle


SOURCES += \
        Test.cpp \
        airport.cpp \
        booking.cpp \
        customer.cpp \
        flightbooking.cpp \
        hotelbooking.cpp \
        idinput.cpp \
        main.cpp \
        myqtablewidgetitem.cpp \
        popup.cpp \
        rentalcarreservation.cpp \
        travel.cpp \
        travelagency.cpp \
        travelagencyui.cpp


HEADERS += \
    Test.h \
    airport.h \
    booking.h \
    customer.h \
    flightbooking.h \
    hotelbooking.h \
    idinput.h \
    myqtablewidgetitem.h \
    popup.h \
    rentalcarreservation.h \
    travel.h \
    travelagency.h \
    travelagencyui.h

FORMS += \
    Customer.ui \
    idinput.ui \
    popup.ui \
    travelagencyui.ui


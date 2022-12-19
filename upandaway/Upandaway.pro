QT       += core gui
QT       += testlib
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle


SOURCES += \
        BookingsInput.cpp \
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
        savejson.cpp \
        sortfunktor.cpp \
        travel.cpp \
        travelagency.cpp \
        travelagencyui.cpp


HEADERS += \
    BookingsInput.h \
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
    savejson.h \
    sortfunktor.h \
    travel.h \
    travelagency.h \
    travelagencyui.h

FORMS += \
    BookingsInput.ui \
    Customer.ui \
    idinput.ui \
    popup.ui \
    savejson.ui \
    travelagencyui.ui


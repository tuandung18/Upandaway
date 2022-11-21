QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle


SOURCES += \
        booking.cpp \
        flightbooking.cpp \
        hotelbooking.cpp \
        idinput.cpp \
        main.cpp \
        popup.cpp \
        rentalcarreservation.cpp \
        travelagency.cpp \
        travelagencyui.cpp

HEADERS += \
    booking.h \
    flightbooking.h \
    hotelbooking.h \
    idinput.h \
    popup.h \
    rentalcarreservation.h \
    travelagency.h \
    travelagencyui.h

FORMS += \
    idinput.ui \
    popup.ui \
    travelagencyui.ui


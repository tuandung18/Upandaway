TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        gateway.cpp \
        knoten.cpp \
        lichtsensor.cpp \
        main.cpp \
        schalter.cpp \
        thermometer.cpp

HEADERS += \
    gateway.h \
    knoten.h \
    lichtsensor.h \
    schalter.h \
    thermometer.h

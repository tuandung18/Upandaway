
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

HEADERS += \
   $$PWD/bestellsystem.h \
   $$PWD/bestellung.h \
   $$PWD/katalog.h \
   $$PWD/kunde.h \
   $$PWD/produkt.h

SOURCES = \
   $$PWD/bestellsystem.cpp \
   $$PWD/bestellung.cpp \
   $$PWD/katalog.cpp \
   $$PWD/kunde.cpp \
   $$PWD/main.cpp \
   $$PWD/produkt.cpp


QT += testlib
QT += core gui
CONFIG += qt warn_on depend_includepath testcase
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app
CONFIG -= app_bundle
CONFIG += console c++11
SOURCES +=  tst_mytestcase.cpp


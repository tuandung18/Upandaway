#include "travelagencyui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TravelAgency* travelAgency;
    travelAgencyUI travelAgencyUI;
    travelAgencyUI.setTravelAgency(travelAgency);
    travelAgencyUI.show();
    return a.exec();
}

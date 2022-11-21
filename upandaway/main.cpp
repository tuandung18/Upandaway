#include "travelagencyui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    travelAgencyUI t;
    t.show();
    return a.exec();
}

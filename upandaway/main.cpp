#include "qtestcase.h"
#include "travelagencyui.h"
#include <Test.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    travelAgencyUI travelAgencyUI;
    travelAgencyUI.show();
//    Test t;
//    QTest::qExec(&t);
    return a.exec();
}

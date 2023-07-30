/********************************************************************************
** Form generated from reading UI file 'BookingsInput.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKINGSINPUT_H
#define UI_BOOKINGSINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookingsInput
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget_3;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget_4;
    QWidget *tab_3;
    QTableWidget *tableWidget_5;
    QPushButton *pushButton;

    void setupUi(QDialog *BookingsInput)
    {
        if (BookingsInput->objectName().isEmpty())
            BookingsInput->setObjectName("BookingsInput");
        BookingsInput->resize(623, 558);
        tabWidget = new QTabWidget(BookingsInput);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(160, 90, 286, 321));
        tab = new QWidget();
        tab->setObjectName("tab");
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setObjectName("horizontalLayout");
        tableWidget_3 = new QTableWidget(tab);
        if (tableWidget_3->columnCount() < 1)
            tableWidget_3->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget_3->rowCount() < 7)
            tableWidget_3->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_3->setItem(0, 0, __qtablewidgetitem8);
        tableWidget_3->setObjectName("tableWidget_3");

        horizontalLayout->addWidget(tableWidget_3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        tableWidget_4 = new QTableWidget(tab_2);
        if (tableWidget_4->columnCount() < 1)
            tableWidget_4->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        if (tableWidget_4->rowCount() < 6)
            tableWidget_4->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(4, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(5, __qtablewidgetitem15);
        tableWidget_4->setObjectName("tableWidget_4");

        verticalLayout_3->addWidget(tableWidget_4);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tableWidget_5 = new QTableWidget(tab_3);
        if (tableWidget_5->columnCount() < 1)
            tableWidget_5->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        if (tableWidget_5->rowCount() < 9)
            tableWidget_5->setRowCount(9);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(4, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(5, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(6, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(7, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(8, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_5->setItem(4, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_5->setItem(5, 0, __qtablewidgetitem27);
        tableWidget_5->setObjectName("tableWidget_5");
        tableWidget_5->setGeometry(QRect(10, 10, 264, 271));
        tabWidget->addTab(tab_3, QString());
        pushButton = new QPushButton(BookingsInput);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(230, 440, 166, 36));

        retranslateUi(BookingsInput);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BookingsInput);
    } // setupUi

    void retranslateUi(QDialog *BookingsInput)
    {
        BookingsInput->setWindowTitle(QCoreApplication::translate("BookingsInput", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("BookingsInput", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_3->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("BookingsInput", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_3->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("BookingsInput", "Startdate", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_3->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("BookingsInput", "Enddate", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_3->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("BookingsInput", "Startlocation", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_3->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("BookingsInput", "Endlocation", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_3->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("BookingsInput", "Company", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_3->verticalHeaderItem(6);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("BookingsInput", "Price", nullptr));

        const bool __sortingEnabled = tableWidget_3->isSortingEnabled();
        tableWidget_3->setSortingEnabled(false);
        tableWidget_3->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("BookingsInput", "Car", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_4->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("BookingsInput", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_4->verticalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("BookingsInput", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_4->verticalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("BookingsInput", "Startdate", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_4->verticalHeaderItem(2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("BookingsInput", "Enddate", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_4->verticalHeaderItem(3);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("BookingsInput", "Hotel", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_4->verticalHeaderItem(4);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("BookingsInput", "Town", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_4->verticalHeaderItem(5);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("BookingsInput", "Price", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("BookingsInput", "Hotel", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_5->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("BookingsInput", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_5->verticalHeaderItem(0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("BookingsInput", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_5->verticalHeaderItem(1);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("BookingsInput", "Startdate", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_5->verticalHeaderItem(2);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("BookingsInput", "Enddate", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_5->verticalHeaderItem(3);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("BookingsInput", "Startlocation", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_5->verticalHeaderItem(4);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("BookingsInput", "Startairport", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_5->verticalHeaderItem(5);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("BookingsInput", "Endlocation", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_5->verticalHeaderItem(6);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("BookingsInput", "Endairport", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_5->verticalHeaderItem(7);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("BookingsInput", "Company", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_5->verticalHeaderItem(8);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("BookingsInput", "Price", nullptr));

        const bool __sortingEnabled1 = tableWidget_5->isSortingEnabled();
        tableWidget_5->setSortingEnabled(false);
        tableWidget_5->setSortingEnabled(__sortingEnabled1);

        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("BookingsInput", "Flight", nullptr));
        pushButton->setText(QCoreApplication::translate("BookingsInput", "Update ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BookingsInput: public Ui_BookingsInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKINGSINPUT_H

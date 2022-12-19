/********************************************************************************
** Form generated from reading UI file 'travelagencyui.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAVELAGENCYUI_H
#define UI_TRAVELAGENCYUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_travelAgencyUI
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *readFile;
    QPushButton *readAirport;
    QPushButton *Customer;
    QPushButton *addCustomer;
    QPushButton *saveJsonButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
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
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *customerName;
    QTableWidget *tableWidget;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *travelID;
    QTableWidget *tableWidget_2;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QMenuBar *menubar;
    QMenu *menuUp_and_away;
    QMenu *menuCustomers;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *travelAgencyUI)
    {
        if (travelAgencyUI->objectName().isEmpty())
            travelAgencyUI->setObjectName("travelAgencyUI");
        travelAgencyUI->resize(960, 825);
        centralwidget = new QWidget(travelAgencyUI);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 60, 168, 218));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        readFile = new QPushButton(layoutWidget);
        readFile->setObjectName("readFile");
        readFile->setLayoutDirection(Qt::LeftToRight);
        readFile->setIconSize(QSize(16, 16));

        verticalLayout->addWidget(readFile);

        readAirport = new QPushButton(layoutWidget);
        readAirport->setObjectName("readAirport");

        verticalLayout->addWidget(readAirport);

        Customer = new QPushButton(layoutWidget);
        Customer->setObjectName("Customer");

        verticalLayout->addWidget(Customer);

        addCustomer = new QPushButton(layoutWidget);
        addCustomer->setObjectName("addCustomer");

        verticalLayout->addWidget(addCustomer);

        saveJsonButton = new QPushButton(layoutWidget);
        saveJsonButton->setObjectName("saveJsonButton");

        verticalLayout->addWidget(saveJsonButton);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(270, 340, 286, 321));
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
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        if (tableWidget_4->rowCount() < 6)
            tableWidget_4->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_4->setVerticalHeaderItem(5, __qtablewidgetitem14);
        tableWidget_4->setObjectName("tableWidget_4");

        verticalLayout_3->addWidget(tableWidget_4);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tableWidget_5 = new QTableWidget(tab_3);
        if (tableWidget_5->columnCount() < 1)
            tableWidget_5->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_5->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        if (tableWidget_5->rowCount() < 9)
            tableWidget_5->setRowCount(9);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(4, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(5, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(6, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(7, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_5->setVerticalHeaderItem(8, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_5->setItem(4, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsDropEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_5->setItem(5, 0, __qtablewidgetitem26);
        tableWidget_5->setObjectName("tableWidget_5");
        tableWidget_5->setGeometry(QRect(10, 10, 264, 271));
        tabWidget->addTab(tab_3, QString());
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(330, 680, 166, 36));
        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(598, 11, 349, 38));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        pushButton_6 = new QPushButton(layoutWidget3);
        pushButton_6->setObjectName("pushButton_6");

        horizontalLayout_6->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(layoutWidget3);
        pushButton_7->setObjectName("pushButton_7");

        horizontalLayout_6->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(layoutWidget3);
        pushButton_8->setObjectName("pushButton_8");

        horizontalLayout_6->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(layoutWidget3);
        pushButton_9->setObjectName("pushButton_9");

        horizontalLayout_6->addWidget(pushButton_9);

        layoutWidget4 = new QWidget(centralwidget);
        layoutWidget4->setObjectName("layoutWidget4");
        layoutWidget4->setGeometry(QRect(280, 50, 271, 241));
        verticalLayout_4 = new QVBoxLayout(layoutWidget4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        customerName = new QLineEdit(layoutWidget4);
        customerName->setObjectName("customerName");
        customerName->setAlignment(Qt::AlignCenter);
        customerName->setReadOnly(true);

        verticalLayout_4->addWidget(customerName);

        tableWidget = new QTableWidget(layoutWidget4);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setText(QString::fromUtf8("ID"));
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem29);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setColumnCount(3);

        verticalLayout_4->addWidget(tableWidget);

        layoutWidget5 = new QWidget(centralwidget);
        layoutWidget5->setObjectName("layoutWidget5");
        layoutWidget5->setGeometry(QRect(620, 50, 311, 235));
        verticalLayout_5 = new QVBoxLayout(layoutWidget5);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        travelID = new QLineEdit(layoutWidget5);
        travelID->setObjectName("travelID");
        travelID->setAlignment(Qt::AlignCenter);
        travelID->setReadOnly(true);

        verticalLayout_5->addWidget(travelID);

        tableWidget_2 = new QTableWidget(layoutWidget5);
        if (tableWidget_2->columnCount() < 4)
            tableWidget_2->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        __qtablewidgetitem30->setText(QString::fromUtf8("ID"));
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem33);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setColumnCount(4);

        verticalLayout_5->addWidget(tableWidget_2);

        layoutWidget6 = new QWidget(centralwidget);
        layoutWidget6->setObjectName("layoutWidget6");
        layoutWidget6->setGeometry(QRect(282, 10, 271, 41));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(layoutWidget6);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_5->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget6);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_5->addWidget(pushButton_3);

        pushButton_5 = new QPushButton(layoutWidget6);
        pushButton_5->setObjectName("pushButton_5");

        horizontalLayout_5->addWidget(pushButton_5);

        travelAgencyUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(travelAgencyUI);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 960, 22));
        menuUp_and_away = new QMenu(menubar);
        menuUp_and_away->setObjectName("menuUp_and_away");
        menuCustomers = new QMenu(menubar);
        menuCustomers->setObjectName("menuCustomers");
        travelAgencyUI->setMenuBar(menubar);
        statusbar = new QStatusBar(travelAgencyUI);
        statusbar->setObjectName("statusbar");
        travelAgencyUI->setStatusBar(statusbar);

        menubar->addAction(menuUp_and_away->menuAction());
        menubar->addAction(menuCustomers->menuAction());

        retranslateUi(travelAgencyUI);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(travelAgencyUI);
    } // setupUi

    void retranslateUi(QMainWindow *travelAgencyUI)
    {
        travelAgencyUI->setWindowTitle(QCoreApplication::translate("travelAgencyUI", "MainWindow", nullptr));
        readFile->setText(QCoreApplication::translate("travelAgencyUI", "Read The File", nullptr));
        readAirport->setText(QCoreApplication::translate("travelAgencyUI", "Read Airport", nullptr));
        Customer->setText(QCoreApplication::translate("travelAgencyUI", "Find Customer", nullptr));
        addCustomer->setText(QCoreApplication::translate("travelAgencyUI", "Add Customer", nullptr));
        saveJsonButton->setText(QCoreApplication::translate("travelAgencyUI", "Save To Json", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("travelAgencyUI", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_3->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("travelAgencyUI", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_3->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("travelAgencyUI", "Startdate", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_3->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("travelAgencyUI", "Enddate", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_3->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("travelAgencyUI", "Startlocation", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_3->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("travelAgencyUI", "Endlocation", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_3->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("travelAgencyUI", "Company", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_3->verticalHeaderItem(6);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("travelAgencyUI", "Price", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("travelAgencyUI", "Car", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_4->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("travelAgencyUI", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_4->verticalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("travelAgencyUI", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_4->verticalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("travelAgencyUI", "Startdate", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_4->verticalHeaderItem(2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("travelAgencyUI", "Enddate", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_4->verticalHeaderItem(3);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("travelAgencyUI", "Hotel", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_4->verticalHeaderItem(4);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("travelAgencyUI", "Town", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_4->verticalHeaderItem(5);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("travelAgencyUI", "Price", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("travelAgencyUI", "Hotel", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_5->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("travelAgencyUI", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_5->verticalHeaderItem(0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("travelAgencyUI", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_5->verticalHeaderItem(1);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("travelAgencyUI", "Startdate", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_5->verticalHeaderItem(2);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("travelAgencyUI", "Enddate", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_5->verticalHeaderItem(3);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("travelAgencyUI", "Startlocation", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_5->verticalHeaderItem(4);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("travelAgencyUI", "Startairport", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_5->verticalHeaderItem(5);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("travelAgencyUI", "Endlocation", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_5->verticalHeaderItem(6);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("travelAgencyUI", "Endairport", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_5->verticalHeaderItem(7);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("travelAgencyUI", "Company", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_5->verticalHeaderItem(8);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("travelAgencyUI", "Price", nullptr));

        const bool __sortingEnabled = tableWidget_5->isSortingEnabled();
        tableWidget_5->setSortingEnabled(false);
        tableWidget_5->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("travelAgencyUI", "Flight", nullptr));
        pushButton->setText(QCoreApplication::translate("travelAgencyUI", "Update ", nullptr));
        pushButton_6->setText(QCoreApplication::translate("travelAgencyUI", "ID", nullptr));
        pushButton_7->setText(QCoreApplication::translate("travelAgencyUI", "Start", nullptr));
        pushButton_8->setText(QCoreApplication::translate("travelAgencyUI", "End", nullptr));
        pushButton_9->setText(QCoreApplication::translate("travelAgencyUI", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("travelAgencyUI", "Startdate", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("travelAgencyUI", "Enddate", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("travelAgencyUI", "Startdate", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("travelAgencyUI", "Enddate", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("travelAgencyUI", "Price", nullptr));
        pushButton_2->setText(QCoreApplication::translate("travelAgencyUI", "ID", nullptr));
        pushButton_3->setText(QCoreApplication::translate("travelAgencyUI", "Start", nullptr));
        pushButton_5->setText(QCoreApplication::translate("travelAgencyUI", "End", nullptr));
        menuUp_and_away->setTitle(QCoreApplication::translate("travelAgencyUI", "Bookings", nullptr));
        menuCustomers->setTitle(QCoreApplication::translate("travelAgencyUI", "Customers", nullptr));
    } // retranslateUi

};

namespace Ui {
    class travelAgencyUI: public Ui_travelAgencyUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAVELAGENCYUI_H

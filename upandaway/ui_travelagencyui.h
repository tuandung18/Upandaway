/********************************************************************************
** Form generated from reading UI file 'travelagencyui.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAVELAGENCYUI_H
#define UI_TRAVELAGENCYUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_travelAgencyUI
{
public:
    QWidget *centralwidget;
    QTabWidget *Information;
    QWidget *Flugbuchung;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_15;
    QLineEdit *FID;
    QLineEdit *FSDate;
    QLineEdit *FEDate;
    QLineEdit *FSFlughafen;
    QLineEdit *FEFlugafen;
    QLineEdit *FCompany;
    QLineEdit *FPrice;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QWidget *HotelBuchung;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *HID;
    QLineEdit *HSDate;
    QLineEdit *HEDate;
    QLineEdit *HHotel;
    QLineEdit *HStadt;
    QLineEdit *HPrice;
    QWidget *layoutWidget_5;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QWidget *AutoBuchung;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *AID;
    QLineEdit *ASDate;
    QLineEdit *AEDate;
    QLineEdit *ASStation;
    QLineEdit *AEStation;
    QLineEdit *ACompany;
    QLineEdit *APrice;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_8;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QPushButton *readFile;
    QPushButton *showBooking;
    QPushButton *showAllBooking;
    QPushButton *saveData;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QListWidget *bookings;
    QMenuBar *menubar;
    QMenu *menuUp_and_away;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *travelAgencyUI)
    {
        if (travelAgencyUI->objectName().isEmpty())
            travelAgencyUI->setObjectName(QString::fromUtf8("travelAgencyUI"));
        travelAgencyUI->resize(736, 576);
        centralwidget = new QWidget(travelAgencyUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Information = new QTabWidget(centralwidget);
        Information->setObjectName(QString::fromUtf8("Information"));
        Information->setGeometry(QRect(310, 30, 321, 301));
        Information->setTabShape(QTabWidget::Rounded);
        Flugbuchung = new QWidget();
        Flugbuchung->setObjectName(QString::fromUtf8("Flugbuchung"));
        groupBox_7 = new QGroupBox(Flugbuchung);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(140, 10, 151, 249));
        verticalLayout_3 = new QVBoxLayout(groupBox_7);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        FID = new QLineEdit(groupBox_7);
        FID->setObjectName(QString::fromUtf8("FID"));

        verticalLayout_15->addWidget(FID);

        FSDate = new QLineEdit(groupBox_7);
        FSDate->setObjectName(QString::fromUtf8("FSDate"));

        verticalLayout_15->addWidget(FSDate);

        FEDate = new QLineEdit(groupBox_7);
        FEDate->setObjectName(QString::fromUtf8("FEDate"));

        verticalLayout_15->addWidget(FEDate);

        FSFlughafen = new QLineEdit(groupBox_7);
        FSFlughafen->setObjectName(QString::fromUtf8("FSFlughafen"));

        verticalLayout_15->addWidget(FSFlughafen);

        FEFlugafen = new QLineEdit(groupBox_7);
        FEFlugafen->setObjectName(QString::fromUtf8("FEFlugafen"));

        verticalLayout_15->addWidget(FEFlugafen);

        FCompany = new QLineEdit(groupBox_7);
        FCompany->setObjectName(QString::fromUtf8("FCompany"));

        verticalLayout_15->addWidget(FCompany);

        FPrice = new QLineEdit(groupBox_7);
        FPrice->setObjectName(QString::fromUtf8("FPrice"));

        verticalLayout_15->addWidget(FPrice);


        verticalLayout_3->addLayout(verticalLayout_15);

        layoutWidget_3 = new QWidget(Flugbuchung);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(30, 40, 87, 201));
        verticalLayout_14 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(layoutWidget_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_14->addWidget(label_15);

        label_16 = new QLabel(layoutWidget_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        verticalLayout_14->addWidget(label_16);

        label_17 = new QLabel(layoutWidget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        verticalLayout_14->addWidget(label_17);

        label_18 = new QLabel(layoutWidget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        verticalLayout_14->addWidget(label_18);

        label_19 = new QLabel(layoutWidget_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        verticalLayout_14->addWidget(label_19);

        label_20 = new QLabel(layoutWidget_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        verticalLayout_14->addWidget(label_20);

        label_21 = new QLabel(layoutWidget_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        verticalLayout_14->addWidget(label_21);

        Information->addTab(Flugbuchung, QString());
        HotelBuchung = new QWidget();
        HotelBuchung->setObjectName(QString::fromUtf8("HotelBuchung"));
        groupBox_2 = new QGroupBox(HotelBuchung);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(100, 10, 161, 241));
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        HID = new QLineEdit(groupBox_2);
        HID->setObjectName(QString::fromUtf8("HID"));

        verticalLayout_4->addWidget(HID);

        HSDate = new QLineEdit(groupBox_2);
        HSDate->setObjectName(QString::fromUtf8("HSDate"));

        verticalLayout_4->addWidget(HSDate);

        HEDate = new QLineEdit(groupBox_2);
        HEDate->setObjectName(QString::fromUtf8("HEDate"));

        verticalLayout_4->addWidget(HEDate);

        HHotel = new QLineEdit(groupBox_2);
        HHotel->setObjectName(QString::fromUtf8("HHotel"));

        verticalLayout_4->addWidget(HHotel);

        HStadt = new QLineEdit(groupBox_2);
        HStadt->setObjectName(QString::fromUtf8("HStadt"));

        verticalLayout_4->addWidget(HStadt);

        HPrice = new QLineEdit(groupBox_2);
        HPrice->setObjectName(QString::fromUtf8("HPrice"));

        verticalLayout_4->addWidget(HPrice);


        verticalLayout_5->addLayout(verticalLayout_4);

        layoutWidget_5 = new QWidget(HotelBuchung);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(20, 40, 71, 191));
        verticalLayout_16 = new QVBoxLayout(layoutWidget_5);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        label_22 = new QLabel(layoutWidget_5);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        verticalLayout_16->addWidget(label_22);

        label_23 = new QLabel(layoutWidget_5);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        verticalLayout_16->addWidget(label_23);

        label_24 = new QLabel(layoutWidget_5);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        verticalLayout_16->addWidget(label_24);

        label_25 = new QLabel(layoutWidget_5);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        verticalLayout_16->addWidget(label_25);

        label_26 = new QLabel(layoutWidget_5);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        verticalLayout_16->addWidget(label_26);

        label_27 = new QLabel(layoutWidget_5);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        verticalLayout_16->addWidget(label_27);

        Information->addTab(HotelBuchung, QString());
        AutoBuchung = new QWidget();
        AutoBuchung->setObjectName(QString::fromUtf8("AutoBuchung"));
        groupBox_4 = new QGroupBox(AutoBuchung);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(140, 10, 151, 249));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        AID = new QLineEdit(groupBox_4);
        AID->setObjectName(QString::fromUtf8("AID"));

        verticalLayout_7->addWidget(AID);

        ASDate = new QLineEdit(groupBox_4);
        ASDate->setObjectName(QString::fromUtf8("ASDate"));

        verticalLayout_7->addWidget(ASDate);

        AEDate = new QLineEdit(groupBox_4);
        AEDate->setObjectName(QString::fromUtf8("AEDate"));

        verticalLayout_7->addWidget(AEDate);

        ASStation = new QLineEdit(groupBox_4);
        ASStation->setObjectName(QString::fromUtf8("ASStation"));

        verticalLayout_7->addWidget(ASStation);

        AEStation = new QLineEdit(groupBox_4);
        AEStation->setObjectName(QString::fromUtf8("AEStation"));

        verticalLayout_7->addWidget(AEStation);

        ACompany = new QLineEdit(groupBox_4);
        ACompany->setObjectName(QString::fromUtf8("ACompany"));

        verticalLayout_7->addWidget(ACompany);

        APrice = new QLineEdit(groupBox_4);
        APrice->setObjectName(QString::fromUtf8("APrice"));

        verticalLayout_7->addWidget(APrice);


        verticalLayout_2->addLayout(verticalLayout_7);

        layoutWidget = new QWidget(AutoBuchung);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 40, 71, 201));
        verticalLayout_8 = new QVBoxLayout(layoutWidget);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_8->addWidget(label);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_8->addWidget(label_2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_8->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_8->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_8->addWidget(label_5);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_8->addWidget(label_6);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_8->addWidget(label_7);

        Information->addTab(AutoBuchung, QString());
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(100, 70, 129, 116));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        readFile = new QPushButton(layoutWidget1);
        readFile->setObjectName(QString::fromUtf8("readFile"));
        readFile->setLayoutDirection(Qt::LeftToRight);
        readFile->setIconSize(QSize(16, 16));

        verticalLayout->addWidget(readFile);

        showBooking = new QPushButton(layoutWidget1);
        showBooking->setObjectName(QString::fromUtf8("showBooking"));

        verticalLayout->addWidget(showBooking);

        showAllBooking = new QPushButton(layoutWidget1);
        showAllBooking->setObjectName(QString::fromUtf8("showAllBooking"));

        verticalLayout->addWidget(showAllBooking);

        saveData = new QPushButton(layoutWidget1);
        saveData->setObjectName(QString::fromUtf8("saveData"));

        verticalLayout->addWidget(saveData);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, 0, 2, 2));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        bookings = new QListWidget(centralwidget);
        bookings->setObjectName(QString::fromUtf8("bookings"));
        bookings->setGeometry(QRect(70, 340, 591, 192));
        travelAgencyUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(travelAgencyUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 736, 21));
        menuUp_and_away = new QMenu(menubar);
        menuUp_and_away->setObjectName(QString::fromUtf8("menuUp_and_away"));
        travelAgencyUI->setMenuBar(menubar);
        statusbar = new QStatusBar(travelAgencyUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        travelAgencyUI->setStatusBar(statusbar);

        menubar->addAction(menuUp_and_away->menuAction());

        retranslateUi(travelAgencyUI);

        Information->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(travelAgencyUI);
    } // setupUi

    void retranslateUi(QMainWindow *travelAgencyUI)
    {
        travelAgencyUI->setWindowTitle(QCoreApplication::translate("travelAgencyUI", "MainWindow", nullptr));
#if QT_CONFIG(whatsthis)
        Information->setWhatsThis(QCoreApplication::translate("travelAgencyUI", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        groupBox_7->setTitle(QCoreApplication::translate("travelAgencyUI", "Flugbuchung", nullptr));
        label_15->setText(QCoreApplication::translate("travelAgencyUI", "ID", nullptr));
        label_16->setText(QCoreApplication::translate("travelAgencyUI", "Startdatum", nullptr));
        label_17->setText(QCoreApplication::translate("travelAgencyUI", "Enddatum", nullptr));
        label_18->setText(QCoreApplication::translate("travelAgencyUI", "Startflughafen", nullptr));
        label_19->setText(QCoreApplication::translate("travelAgencyUI", "Endflughafen", nullptr));
        label_20->setText(QCoreApplication::translate("travelAgencyUI", "Fluggesellschaft", nullptr));
        label_21->setText(QCoreApplication::translate("travelAgencyUI", "Preis", nullptr));
        Information->setTabText(Information->indexOf(Flugbuchung), QCoreApplication::translate("travelAgencyUI", "Tab 1", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("travelAgencyUI", "Hotelbuchung", nullptr));
        label_22->setText(QCoreApplication::translate("travelAgencyUI", "ID", nullptr));
        label_23->setText(QCoreApplication::translate("travelAgencyUI", "Startdatum", nullptr));
        label_24->setText(QCoreApplication::translate("travelAgencyUI", "Enddatum", nullptr));
        label_25->setText(QCoreApplication::translate("travelAgencyUI", "Hotel", nullptr));
        label_26->setText(QCoreApplication::translate("travelAgencyUI", "Stadt", nullptr));
        label_27->setText(QCoreApplication::translate("travelAgencyUI", "Price", nullptr));
        Information->setTabText(Information->indexOf(HotelBuchung), QCoreApplication::translate("travelAgencyUI", "Tab 2", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("travelAgencyUI", "Autobuchung", nullptr));
        label->setText(QCoreApplication::translate("travelAgencyUI", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("travelAgencyUI", "Startdate", nullptr));
        label_3->setText(QCoreApplication::translate("travelAgencyUI", "Enddate", nullptr));
        label_4->setText(QCoreApplication::translate("travelAgencyUI", "Startstation", nullptr));
        label_5->setText(QCoreApplication::translate("travelAgencyUI", "Endstation", nullptr));
        label_6->setText(QCoreApplication::translate("travelAgencyUI", "Company", nullptr));
        label_7->setText(QCoreApplication::translate("travelAgencyUI", "Preis", nullptr));
        Information->setTabText(Information->indexOf(AutoBuchung), QCoreApplication::translate("travelAgencyUI", "Page", nullptr));
        readFile->setText(QCoreApplication::translate("travelAgencyUI", "Read The File", nullptr));
        showBooking->setText(QCoreApplication::translate("travelAgencyUI", "Show Booking", nullptr));
        showAllBooking->setText(QCoreApplication::translate("travelAgencyUI", "Show All Bookings", nullptr));
        saveData->setText(QCoreApplication::translate("travelAgencyUI", "Save Data", nullptr));
        menuUp_and_away->setTitle(QCoreApplication::translate("travelAgencyUI", "Welcome", nullptr));
    } // retranslateUi

};

namespace Ui {
    class travelAgencyUI: public Ui_travelAgencyUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAVELAGENCYUI_H

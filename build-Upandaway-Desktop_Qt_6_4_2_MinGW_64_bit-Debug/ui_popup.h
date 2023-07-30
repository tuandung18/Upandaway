/********************************************************************************
** Form generated from reading UI file 'popup.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POPUP_H
#define UI_POPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Popup
{
public:
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *fehlerAusgabe;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *wiederholen;
    QPushButton *abbrechen;
    QLabel *behandlungsAnweisung;

    void setupUi(QDialog *Popup)
    {
        if (Popup->objectName().isEmpty())
            Popup->setObjectName("Popup");
        Popup->resize(437, 428);
        groupBox = new QGroupBox(Popup);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(40, 20, 361, 371));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        fehlerAusgabe = new QLabel(groupBox);
        fehlerAusgabe->setObjectName("fehlerAusgabe");
        fehlerAusgabe->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(fehlerAusgabe);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName("groupBox_2");
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        wiederholen = new QPushButton(groupBox_2);
        wiederholen->setObjectName("wiederholen");

        horizontalLayout->addWidget(wiederholen);

        abbrechen = new QPushButton(groupBox_2);
        abbrechen->setObjectName("abbrechen");

        horizontalLayout->addWidget(abbrechen);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addWidget(groupBox_2);

        behandlungsAnweisung = new QLabel(groupBox);
        behandlungsAnweisung->setObjectName("behandlungsAnweisung");
        behandlungsAnweisung->setScaledContents(true);
        behandlungsAnweisung->setAlignment(Qt::AlignCenter);
        behandlungsAnweisung->setWordWrap(true);

        verticalLayout->addWidget(behandlungsAnweisung);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Popup);

        QMetaObject::connectSlotsByName(Popup);
    } // setupUi

    void retranslateUi(QDialog *Popup)
    {
        Popup->setWindowTitle(QCoreApplication::translate("Popup", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Popup", "Fehler Ausgabe", nullptr));
        fehlerAusgabe->setText(QCoreApplication::translate("Popup", "TextLabel", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Popup", "Auswahl", nullptr));
        wiederholen->setText(QCoreApplication::translate("Popup", "Wiederholen", nullptr));
        abbrechen->setText(QCoreApplication::translate("Popup", "Abbrechen", nullptr));
        behandlungsAnweisung->setText(QCoreApplication::translate("Popup", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Popup: public Ui_Popup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POPUP_H

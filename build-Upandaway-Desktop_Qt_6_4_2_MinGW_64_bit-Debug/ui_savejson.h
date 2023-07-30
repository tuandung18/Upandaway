/********************************************************************************
** Form generated from reading UI file 'savejson.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEJSON_H
#define UI_SAVEJSON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SaveJson
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pricePara;
    QPushButton *fromPara;
    QPushButton *toPara;

    void setupUi(QDialog *SaveJson)
    {
        if (SaveJson->objectName().isEmpty())
            SaveJson->setObjectName("SaveJson");
        SaveJson->resize(747, 598);
        layoutWidget = new QWidget(SaveJson);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(210, 90, 311, 441));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pricePara = new QPushButton(layoutWidget);
        pricePara->setObjectName("pricePara");

        verticalLayout->addWidget(pricePara);

        fromPara = new QPushButton(layoutWidget);
        fromPara->setObjectName("fromPara");

        verticalLayout->addWidget(fromPara);

        toPara = new QPushButton(layoutWidget);
        toPara->setObjectName("toPara");

        verticalLayout->addWidget(toPara);


        retranslateUi(SaveJson);

        QMetaObject::connectSlotsByName(SaveJson);
    } // setupUi

    void retranslateUi(QDialog *SaveJson)
    {
        SaveJson->setWindowTitle(QCoreApplication::translate("SaveJson", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("SaveJson", "ID", nullptr));
        pricePara->setText(QCoreApplication::translate("SaveJson", "Price", nullptr));
        fromPara->setText(QCoreApplication::translate("SaveJson", "From Date", nullptr));
        toPara->setText(QCoreApplication::translate("SaveJson", "To Date", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SaveJson: public Ui_SaveJson {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEJSON_H

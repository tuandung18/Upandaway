/********************************************************************************
** Form generated from reading UI file 'customersearch.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERSEARCH_H
#define UI_CUSTOMERSEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_CustomerSearch
{
public:
    QHBoxLayout *horizontalLayout;
    QTableWidget *tableWidget;

    void setupUi(QDialog *CustomerSearch)
    {
        if (CustomerSearch->objectName().isEmpty())
            CustomerSearch->setObjectName("CustomerSearch");
        CustomerSearch->resize(608, 432);
        horizontalLayout = new QHBoxLayout(CustomerSearch);
        horizontalLayout->setObjectName("horizontalLayout");
        tableWidget = new QTableWidget(CustomerSearch);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget->setObjectName("tableWidget");

        horizontalLayout->addWidget(tableWidget);


        retranslateUi(CustomerSearch);

        QMetaObject::connectSlotsByName(CustomerSearch);
    } // setupUi

    void retranslateUi(QDialog *CustomerSearch)
    {
        CustomerSearch->setWindowTitle(QCoreApplication::translate("CustomerSearch", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CustomerSearch", "Customer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CustomerSearch: public Ui_CustomerSearch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMERSEARCH_H

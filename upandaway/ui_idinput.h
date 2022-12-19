/********************************************************************************
** Form generated from reading UI file 'idinput.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IDINPUT_H
#define UI_IDINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_idInput
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *ok;
    QPushButton *abbrechen;

    void setupUi(QDialog *idInput)
    {
        if (idInput->objectName().isEmpty())
            idInput->setObjectName("idInput");
        idInput->resize(259, 120);
        verticalLayout_2 = new QVBoxLayout(idInput);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(idInput);
        label->setObjectName("label");
        label->setScaledContents(true);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(idInput);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(lineEdit);

        verticalSpacer = new QSpacerItem(17, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        ok = new QPushButton(idInput);
        ok->setObjectName("ok");

        horizontalLayout->addWidget(ok);

        abbrechen = new QPushButton(idInput);
        abbrechen->setObjectName("abbrechen");

        horizontalLayout->addWidget(abbrechen);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(idInput);

        QMetaObject::connectSlotsByName(idInput);
    } // setupUi

    void retranslateUi(QDialog *idInput)
    {
        idInput->setWindowTitle(QCoreApplication::translate("idInput", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("idInput", "ID or Name", nullptr));
        ok->setText(QCoreApplication::translate("idInput", "OK", nullptr));
        abbrechen->setText(QCoreApplication::translate("idInput", "Abbrechen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class idInput: public Ui_idInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IDINPUT_H

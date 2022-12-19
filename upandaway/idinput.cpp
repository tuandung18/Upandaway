#include "idinput.h"
#include "ui_idinput.h"
#include <iostream>
idInput::idInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::idInput)
{
    ui->setupUi(this);
}

idInput::~idInput()
{
    delete ui;
}


void idInput::on_ok_clicked()
{


    setSavedID(ui->lineEdit->text().toInt());
    setSavedCustomerName(ui->lineEdit->text().toStdString());

    close();
}

std::string idInput::getSavedCustomerName() const
{
    return savedCustomerName;
}

void idInput::setSavedCustomerName(const std::string &newSavedCustomerName)
{
    savedCustomerName = newSavedCustomerName;
}

void idInput::setSavedID(int newSavedID)
{
    savedID = newSavedID;
}

int idInput::getSavedID() const
{
    return savedID;
}


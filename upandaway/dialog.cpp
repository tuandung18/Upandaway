#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::addItem(shared_ptr<Travel> t)
{



    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row,0,new QTableWidgetItem(QString::fromStdString(to_string(t->getId()))));

    if(t->checkEnoughHotels())
        ui->tableWidget->setItem(row,1,new QTableWidgetItem(QString("o")));
    else         ui->tableWidget->setItem(row,1,new QTableWidgetItem(QString("X")));

    if(t->checkNoUselessHotel())
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString("o")));
    else         ui->tableWidget->setItem(row,2,new QTableWidgetItem(QString("X")));

    if(t->checkNoUselessRentalCars())
        ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString("o")));
    else         ui->tableWidget->setItem(row,3,new QTableWidgetItem(QString("X")));

    if(t->checkRoundTrip())
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(QString("o")));
    else         ui->tableWidget->setItem(row,4,new QTableWidgetItem(QString("X")));

    row++;


}

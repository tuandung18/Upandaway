#include "customersearch.h"
#include "ui_customersearch.h"

CustomerSearch::CustomerSearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerSearch)
{
    ui->setupUi(this);
}

CustomerSearch::~CustomerSearch()
{
    delete ui;
}

void CustomerSearch::setupTable(vector<std::shared_ptr<Customer> > allCustomers)
{
    int row = 0;
    for(const auto &c : allCustomers){
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0,new QTableWidgetItem(QString::fromStdString(c->getName())));
        row++;
    }
}

void CustomerSearch::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    savedCustomName= item->text().toStdString();
    close();

}


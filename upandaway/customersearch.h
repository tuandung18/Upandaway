#ifndef CUSTOMERSEARCH_H
#define CUSTOMERSEARCH_H

#include "customer.h"
#include "qtablewidget.h"
#include <QDialog>

namespace Ui {
class CustomerSearch;
}

class CustomerSearch : public QDialog
{
    Q_OBJECT

public:
    explicit CustomerSearch(QWidget *parent = nullptr);
    ~CustomerSearch();
    void setupTable (vector<std::shared_ptr<Customer> >allCustomers);
    string savedCustomName;
private slots:
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::CustomerSearch *ui;
};

#endif // CUSTOMERSEARCH_H

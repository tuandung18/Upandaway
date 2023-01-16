#ifndef CHECKS_H
#define CHECKS_H

#include "qtablewidget.h"
#include "travel.h"
#include <QMainWindow>

namespace Ui {
class Checks;
}

class Checks : public QMainWindow
{
    Q_OBJECT

public:
    explicit Checks(QWidget *parent = nullptr);
    ~Checks();
    void addItem(shared_ptr<Travel> t);

private:
    Ui::Checks *ui;
    int row = 0;
};

#endif // CHECKS_H

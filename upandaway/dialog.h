#ifndef DIALOG_H
#define DIALOG_H

#include "travel.h"
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void addItem(shared_ptr<Travel> t);

private:
    Ui::Dialog *ui;
    int row = 0;
};

#endif // DIALOG_H

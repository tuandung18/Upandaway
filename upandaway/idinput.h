#ifndef IDINPUT_H
#define IDINPUT_H

#include <QDialog>
#include <string>
#include <QString>
namespace Ui {
class idInput;
}

class idInput : public QDialog
{
    Q_OBJECT

public:
    explicit idInput(QWidget *parent = nullptr);
    ~idInput();

    int getSavedID() const;

    void setSavedID(int newSavedID);

    std::string getSavedCustomerName() const;
    void setSavedCustomerName(const std::string &newSavedCustomerName);

private slots:


    void on_ok_clicked();

private:
    Ui::idInput *ui;
    int savedID;
    std::string savedCustomerName;
};

#endif // IDINPUT_H

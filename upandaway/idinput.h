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

private slots:


    void on_ok_clicked();

private:
    Ui::idInput *ui;
    int savedID;
};

#endif // IDINPUT_H

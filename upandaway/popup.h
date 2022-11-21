#ifndef POPUP_H
#define POPUP_H
#include <travelagency.h>
#include <QDialog>

namespace Ui {
class Popup;
}

class Popup : public QDialog
{
    Q_OBJECT

public:
    explicit Popup(QWidget *parent = nullptr);
    ~Popup();
    void about (QWidget *parent, const QString &title, const QString &text);
    bool getRetry() const;

private slots:
    void on_wiederholen_clicked();

    void on_abbrechen_clicked();

private:
    bool retry;
    Ui::Popup *ui;
};

#endif // POPUP_H

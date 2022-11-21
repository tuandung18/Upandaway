#ifndef UPANDAWAY_H
#define UPANDAWAY_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Upandaway; }
QT_END_NAMESPACE

class Upandaway : public QMainWindow
{
    Q_OBJECT

public:
    Upandaway(QWidget *parent = nullptr);
    ~Upandaway();

private:
    Ui::Upandaway *ui;
};
#endif // UPANDAWAY_H

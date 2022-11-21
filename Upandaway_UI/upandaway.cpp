#include "upandaway.h"
#include "ui_upandaway.h"

Upandaway::Upandaway(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Upandaway)
{
    ui->setupUi(this);
}

Upandaway::~Upandaway()
{
    delete ui;
}


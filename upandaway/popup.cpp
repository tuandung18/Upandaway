#include "popup.h"
#include "ui_popup.h"

Popup::Popup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Popup)
{
    ui->setupUi(this);
}

Popup::~Popup()
{
    delete ui;
}

void Popup::about(QWidget *parent, const QString &title, const QString &text)
{
    parent->setWindowTitle(title);
    ui->fehlerAusgabe->setText(text);
    ui->behandlungsAnweisung->setText("Datei korrigiert? Dann 'Wiederholen'. Waelen Sie 'Abbrechen' um diesen Dialog zu verlassen");
}

void Popup::on_wiederholen_clicked()
{

    this->close();
}

bool Popup::getRetry() const
{
    return retry;
}


void Popup::on_abbrechen_clicked()
{
    exit(0);
    delete this;
}


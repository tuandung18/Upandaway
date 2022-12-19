#include "savejson.h"
#include "ui_savejson.h"

SaveJson::SaveJson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveJson)
{
    ui->setupUi(this);
}

SaveJson::~SaveJson()
{
    delete ui;
}

SortFunktor::SortierParameter SaveJson::getPara() const
{
    return para;
}

void SaveJson::setPara(SortFunktor::SortierParameter newPara)
{
    para = newPara;
}

void SaveJson::on_pushButton_clicked()
{
    setPara(SortFunktor::ID);
    this->close();
}


void SaveJson::on_pricePara_clicked()
{
    setPara(SortFunktor::PRICE);
    this->close();

}


void SaveJson::on_fromPara_clicked()
{
    setPara(SortFunktor::FROMDATE);
    this->close();

}


void SaveJson::on_toPara_clicked()
{
    setPara(SortFunktor::TODATE);
    this->close();

}


#ifndef SAVEJSON_H
#define SAVEJSON_H

#include <QDialog>
#include <sortfunktor.h>

namespace Ui {
class SaveJson;
}

class SaveJson : public QDialog
{
    Q_OBJECT

public:
    explicit SaveJson(QWidget *parent = nullptr);
    ~SaveJson();
    SortFunktor::SortierParameter getPara() const;
    void setPara(SortFunktor::SortierParameter newPara);


private slots:
    void on_pushButton_clicked();

    void on_pricePara_clicked();

    void on_fromPara_clicked();

    void on_toPara_clicked();

private:
    Ui::SaveJson *ui;
    SortFunktor::SortierParameter para = SortFunktor::ID;

};

#endif // SAVEJSON_H

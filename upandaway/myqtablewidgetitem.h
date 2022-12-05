#ifndef MYQTABLEWIDGETITEM_H
#define MYQTABLEWIDGETITEM_H
#include<QTableWidgetItem>

class MyQTableWidgetItem : public QTableWidgetItem
{
public:

    MyQTableWidgetItem(const QString &text);

    bool operator <(const MyQTableWidgetItem &other) const
    {
        return text().toInt() < other.text().toInt();
    }

};

#endif // MYQTABLEWIDGETITEM_H

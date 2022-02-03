#ifndef KNOTEN_H
#define KNOTEN_H


class Knoten
{
public:
    Knoten();
    Knoten(int);
    static int cnt;
    static Knoten* oben;
    void drauflegen(int);
    void runternehmen();
    int getInfo() const;
    void setInfo(int newInfo);
    Knoten *getNext() const;
    void setNext(Knoten *newNext);
    int top ();

private:
    int info;
    Knoten* next;
};

#endif // KNOTEN_H

#ifndef KNOTEN_H
#define KNOTEN_H


class knoten
{
public:
    knoten();
    virtual double Abfrage () ;
    virtual void Setzen (double) ;
    virtual void Einheit();
    virtual void Name() ;
    virtual ~knoten();
};

#endif // KNOTEN_H

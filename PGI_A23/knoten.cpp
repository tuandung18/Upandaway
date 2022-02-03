#include "knoten.h"
#include <iostream>
int Knoten::cnt = 0;
Knoten* Knoten::oben = NULL;
Knoten::Knoten()
{
    cnt++;

}

Knoten::Knoten(int i)
    :info(i)
{
    cnt++;

}

int Knoten::getInfo() const
{
    return info;
}

void Knoten::setInfo(int newInfo)
{
    info = newInfo;
}

Knoten *Knoten::getNext() const
{
    return next;
}

void Knoten::setNext(Knoten *newNext)
{
    next = newNext;
}

int Knoten::top()
{
    return Knoten::oben->getInfo();
}
void Knoten::drauflegen(int x) {
 Knoten *p = new Knoten;
 p->setInfo(x);
 p->setNext(Knoten::oben);
 Knoten::oben = p;
 Knoten::cnt++;
}
void Knoten::runternehmen() {
 Knoten * help;

 if (Knoten::cnt == 0)
 help = NULL;
 else {
 help = Knoten::oben->getNext();
 Knoten::cnt--;
 }

 delete Knoten::oben;

 Knoten::oben = help;
}

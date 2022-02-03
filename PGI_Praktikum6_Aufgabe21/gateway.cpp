#include "gateway.h"

gateway::gateway()

{
    K = new knoten*[5];
    K[0] = new Lichtsensor();
    K[1] = new Thermometer();
    K[2] = new Thermometer();
    K[3] = new Schalter();
    K[4] = new Schalter();
}
gateway::~gateway(){
    delete []K;
}

knoten *gateway::getKnoten(int i)
{
    return K[i];
}

knoten **gateway::getK() const
{
    return K;
}

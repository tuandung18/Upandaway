#ifndef GATEWAY_H
#define GATEWAY_H
#include "knoten.h"
#include "lichtsensor.h"
#include "schalter.h"
#include "thermometer.h"
#include <vector>
using namespace std;
class gateway
{
public:
    gateway();
    virtual ~gateway();
    knoten* getKnoten(int i);
    knoten **getK() const;

private:
    int length;
    knoten** K;
};

#endif // GATEWAY_H

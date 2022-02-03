#include "lichtsensor.h"
#include <iostream>
#include <time.h>
#include <random>
using namespace std;
Lichtsensor::Lichtsensor()
{
    srand(time(NULL));
}

double Lichtsensor::Abfrage()
{
    return 12000*((double)rand()/(double)RAND_MAX);
}

void Lichtsensor::Setzen(double d)
{
    cout << "Der Zustand des Lichtsensor laesst sich durch das Gateway nicht veraendern."<<endl;
}

void Lichtsensor::Einheit()
{
    cout << " Lux"<<endl;
}

void Lichtsensor::Name()
{
    cout << "Lichtsensor";
}

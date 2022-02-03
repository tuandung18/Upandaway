#include "thermometer.h"
#include <random>
#include <time.h>
#include <iostream>
using namespace std;
Thermometer::Thermometer()
{
    srand (time(NULL));
}

double Thermometer::Abfrage()
{
    return 40*((double)rand()/(double)RAND_MAX) + 20;
}

void Thermometer::Setzen(double d)
{
    cout << "Zustand des Thermometer laesst sich durch das Gateway nicht aendern" << endl;
}

void Thermometer::Einheit()
{
    cout <<" Grad Celsius."<<endl;
}

void Thermometer::Name()
{
    cout <<"Thermometer";
}




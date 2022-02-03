#include <iostream>

#include "Aufgabe14.h"

using namespace std;

Tag toTag (Block block){
    Tag result = (Tag)((int) block / 7);
    return result;
}
void toBlockName (int i)
{
    switch (i) {
    case 0:
        cout<<"Montag"<<endl;
        break;
    case 1:
        cout<<"Dienstag"<<endl;
        break;
    case 2:
        cout<<"Mittwoch"<<endl;
        break;
    case 3:
        cout<<"Donnerstag"<<endl;
        break;
    case 4:
        cout<<"Fritag"<<endl;
        break;
    case 5:
        cout<<"Samstag"<<endl;
        break;

    }
}
bool blockChecker (Block block)
{
    if(toTag(block)==Tag::DI and block>=Block::Di3)
        return true;
    else return false;
}


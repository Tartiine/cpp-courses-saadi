#include <string>
#include <iostream>

#include "headers/energy_card.h"

using namespace std;

EnergyCard::EnergyCard(const string &name)
: Card(name)
{
}


void EnergyCard::displayInfo() const {
    cout << "Energy Card - Type: " << this->getName(); 
}

#include <string>
#include <iostream>

#include "headers/card.h"

Card::Card(const string& name) : cardName(name) {
}

void Card::displayInfo() const{
    cout <<  this->cardName << endl;
}

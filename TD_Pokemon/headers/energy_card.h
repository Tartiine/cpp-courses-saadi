#ifndef ENERGY_CARD_H
#define ENERGY_CARD_H
#include <string>
#include <iostream>
#include "Card.h" 

class EnergyCard : public Card{
    public:
        EnergyCard(const string &name);
        void displayInfo() const override;

    private:
        string cardName;
};

#endif

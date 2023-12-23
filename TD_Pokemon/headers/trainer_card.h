#ifndef TRAINER_CARD_H
#define TRAINER_CARD_H

#include <string>
#include "Card.h" 

class TrainerCard : public Card {
public:
    TrainerCard(const string& name, const string& effect);
    string getEffect() const;
    void displayInfo() const override;

private:
    string effect;
};

#endif
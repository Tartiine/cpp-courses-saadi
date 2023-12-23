#include "headers/trainer_card.h"

TrainerCard::TrainerCard(const string& name, const string& effect)
    : Card(name), effect(effect) {}

string TrainerCard::getEffect() const {
    return effect;
}

void TrainerCard::displayInfo() const {
    cout << "Trainer Card - Name: " << this->getName() << ", Effect: " << effect; 
}

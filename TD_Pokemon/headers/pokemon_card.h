#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H

#include "card.h" 
#include <string>
#include <iostream>
#include <vector>
#include <tuple> 
#include "player.h"
using namespace std;

class PokemonCard : public Card {
public:
    PokemonCard(const string& name, const string& pokemonType, const string& familyName, 
                int evolutionLevel, int maxHP, int energyCost, 
                const string& firstAttackName, int firstAttackDamage, 
                int secondAttackCost, const string& secondAttackName, int secondAttackDamage);

    void attacks(const vector<tuple<int, int, string, int>>& attackDetails);
    void addEnergy(const string &energyType);
    void displayInfo() const override;
    void performAttack(int attackIndex, PokemonCard &targetPokemon);
    int getCurrentHP() const {
        return currentHP;
    }

private:
    string cardName;
    string pokemonType;
    string familyName;
    int evolutionLevel;
    int maxHP;
    int currentHP;
    int energyCost;
    vector<tuple<int, int, string, int>> attackDetails; 
};

#endif 

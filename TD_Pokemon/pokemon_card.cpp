#include <string>
#include <iostream>
#include <vector>
#include <tuple>

#include "headers/pokemon_card.h"
using namespace std;


PokemonCard::PokemonCard(const string &name, const string &type, const string &family, 
                         int evolutionLevel, int hp, int energyCost, 
                         const string &firstAttack, int damage1, 
                         int secondAttackCost, const string &secondAttack, int damage2) 
: Card(name), pokemonType(type), familyName(family), 
  evolutionLevel(evolutionLevel), maxHP(hp), currentHP(hp), 
  energyCost(energyCost)
{
    attackDetails.push_back(make_tuple(energyCost, 0, firstAttack, damage1));
    attackDetails.push_back(make_tuple(secondAttackCost, 0, secondAttack, damage2));
}


void PokemonCard::attacks(const vector<tuple<int, int, string, int>> &newAttackDetails){
    attackDetails = newAttackDetails;
}

void PokemonCard::addEnergy(const string& energyType) {
    if (pokemonType == energyType) {
        for (auto& attack : attackDetails) {
            get<1>(attack)++; 
        }
    }
}

void PokemonCard::displayInfo() const {
    cout << "Pokemon Card - Name: " << getName() 
         << ", Type: " << pokemonType 
         << ", Evolution Level: " << evolutionLevel 
         << " of the family \"" << familyName 
         << "\", HP: " << currentHP
         << "\nAttacks:" << endl;

    int index = 0; 
    for (const auto& attack : attackDetails) {
        cout << "Attack #" << index
            << "\n  Attack cost: " << get<0>(attack) 
            << "\n  Current energy storage: " << get<1>(attack) 
            << "\n  Attack description: " << get<2>(attack) 
            << "\n  Attack damage: " << get<3>(attack) 
            << endl;

        index++; 
    }
}



void PokemonCard::performAttack(int attackIndex, PokemonCard& targetPokemon) {
    if (attackIndex < attackDetails.size()) {
        auto& attack = attackDetails[attackIndex];
        if (get<1>(attack) >= get<0>(attack)) { 
            targetPokemon.currentHP -= get<3>(attack); 
            get<1>(attack) = 0; 
        }
    }
}




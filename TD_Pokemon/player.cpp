#include <string>
#include <iostream>
#include "headers/player.h"
#include "headers/energy_card.h"
#include "headers/pokemon_card.h"
#include "headers/trainer_card.h"
using namespace std;

Player::Player(const string& name) : name(name) {}

void Player::attachEnergyCard(int energyCardIndex, int pokemonCardIndex) {
    if (energyCardIndex < bench.size() && pokemonCardIndex < action.size()) {
        EnergyCard* energyCard = dynamic_cast<EnergyCard*>(bench[energyCardIndex]);
        if (energyCard != nullptr) {
            PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(action[pokemonCardIndex]);
            if (pokemonCard != nullptr) {
                string energyType = energyCard->getName(); 
                pokemonCard->addEnergy(energyType); 

                cout << name << " is attaching Energy Card of type " << energyType 
                     << " to the Pokemon " << pokemonCard->getName() << endl;
                delete bench[energyCardIndex]; 
                bench.erase(bench.begin() + energyCardIndex); 
            }
        }
    }
    //TODO: Energy card must be deleted from the bench but it is not the case
    //TODO: Verify if the energy card is the same type as the pokemon type
}

void Player::activatePokemonCard(int cardIndex) {
    PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(bench[cardIndex]);
    if (pokemonCard != nullptr) {
        action.push_back(pokemonCard);
        bench.erase(bench.begin() + cardIndex);
        cout << name << " is activating a Pokemon Card: " << pokemonCard->getName() << endl;
    }
}


void Player::addCardToBench(Card* card) {
    bench.push_back(card);
}

void Player::displayAction() {
    for (auto& card : action) {
        card->displayInfo();
    }
}

void Player::displayBench() {
    cout << "Bench cards for Player " << name << ":" << endl;
    for (const auto& card : bench) {
        card->displayInfo();
    }
}



void Player::attack(int attackerIndex, int attackIndex, Player& target, int targetIndex) {
    if (attackerIndex < action.size()) {
        PokemonCard* attacker = dynamic_cast<PokemonCard*>(action[attackerIndex]);
        if (attacker != nullptr && targetIndex < target.action.size()) {
            PokemonCard* targetPokemon = dynamic_cast<PokemonCard*>(target.action[targetIndex]);
            if (targetPokemon != nullptr) {
                attacker->performAttack(attackIndex, *targetPokemon);
            }
        } //TODO: Deux attaques maximum
    }
}


void Player::useTrainer(int trainerIndex) {
    TrainerCard* trainerCard = dynamic_cast<TrainerCard*>(bench[trainerIndex]);
    if (trainerCard != nullptr) {
        cout << name << " is using the Trainer Card to \"" << trainerCard->getEffect() << "\"" << endl;
    }
}//TODO: Add max HP to every pokemons


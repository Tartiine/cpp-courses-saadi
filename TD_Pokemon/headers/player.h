#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include "card.h"
#include <vector>

class Player{
    public:
        Player(const string& name);
        void attachEnergyCard(int,int);
        void activatePokemonCard(int);
        void addCardToBench(Card *);
        void displayBench();
        void displayAction();
        void attack(int, int, Player&, int);
        void useTrainer(int);
        void removeDefeatedPokemon(int index);

    private:
        string name;
        vector<Card*> bench;
        vector<Card*> action;

};

#endif

#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>
using namespace std;

class Card{
    public:
        Card(const string& name);
        virtual void displayInfo() const;
        virtual string getName() const {
            return cardName;
        }

    private:
        string cardName;

};

#endif 
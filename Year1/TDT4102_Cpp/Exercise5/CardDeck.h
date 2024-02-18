#pragma once
#include "Card.h"
#include <string>
#include <vector>

class CardDeck {
    private:
        std::vector<Card> cards;
    public:
        //default constructor
        CardDeck();

        void swap(int cardIndex1, int cardIndex2);
        void print();
        void shuffle();
        Card drawCard();
};

int randomWithLimits(int lowerLimit, int upperLimit);

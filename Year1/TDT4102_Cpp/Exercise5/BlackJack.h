#pragma once
#include "Card.h"
#include "CardDeck.h"
#include <string>
#include <vector>

class BlackJack {
    private:
        CardDeck deck;
        std::vector<Card> playerHand;
        std::vector<Card> dealerHand;
        int playerHandSum;
        int dealerHandSum;
    public:
        BlackJack();
        bool isAce(Card card);
        int getHandScore(std::vector<Card> hand);
        bool askPlayerDrawCard();
        void drawPlayerCard();
        void drawDealerCard();
        void playGame();
};


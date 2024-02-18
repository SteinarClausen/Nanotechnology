#include "Card.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "CardDeck.h"
#include <random>

int randomWithLimits(int lowerLimit, int upperLimit) {
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution<int> distribution(lowerLimit,upperLimit);
    return distribution(generator);
}

CardDeck::CardDeck() {
    for (int s = static_cast<int>(Suit::clubs); s <= static_cast<int>(Suit::spades); s++){
        for (int r = static_cast<int>(Rank::two); r <= static_cast<int>(Rank::ace); r++) {
            cards.push_back(Card(static_cast<Suit>(s),static_cast<Rank>(r)));
        }
    }
}

void CardDeck::swap(int cardIndex1,int cardIndex2) {
    if ((cardIndex1 < 0 || cardIndex1 >= cards.size())||(cardIndex2 < 0 || cardIndex2 >= cards.size())) {
        return;
    }
    std::swap(cards[cardIndex1],cards[cardIndex2]);
}

void CardDeck::print() {
    for(Card card : cards) {
        card.toString();
        std::cout << ", ";
        
    }
}

void CardDeck::shuffle() {
    for (int i = 0; i < cards.size()*4; i++) {
        int cardIndex1 = randomWithLimits(0,cards.size());
        int cardIndex2 = randomWithLimits(0,cards.size());
        if (cardIndex1 != cardIndex2) {
            CardDeck::swap(cardIndex1,cardIndex2);
        }
    }
}

Card CardDeck::drawCard() {
    if (cards.empty()){
        std::cout << "The deck is empty." << std::endl;
        throw std::runtime_error("The deck is empty.");
    }
    Card drawnCard = cards.back();
    cards.pop_back();
    return drawnCard;
}
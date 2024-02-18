#include "Card.h"
#include <string>
#include <iostream>
#include <map>
#include "CardDeck.h"

std::string suitToString(Suit suit) {
    static const std::map<Suit, std::string> suitMap {
        {Suit::spades, "Spades"},
        {Suit::hearts, "Hearts"},
        {Suit::diamonds, "Diamonds"},
        {Suit::clubs, "Clubs"},
    };
    auto iteration = suitMap.find(suit);
    if (iteration != suitMap.end()) {
        return iteration->second;
    } else {
        return "Not a card suit";
    }
}

std::string rankToString(Rank rank) {
    static const std::map<Rank, std::string> rankMap {
        {Rank::two, "Two"},
        {Rank::three, "Three"},
        {Rank::four, "Four"},
        {Rank::five, "Five"},
        {Rank::six, "Six"},
        {Rank::seven, "Seven"},
        {Rank::eight, "Eight"},
        {Rank::nine, "Nine"},
        {Rank::ten, "Ten"},
        {Rank::jack, "Jack"},
        {Rank::queen, "Queen"},
        {Rank::king, "King"},
        {Rank::ace, "Ace"}
    };
    auto iteration = rankMap.find(rank);
    if (iteration!=rankMap.end()) {
        return iteration->second;
    } else {
        return "Not a card rank";
    }
}

std::string Card::getSuit() {
    return suitToString(s);
}

std::string Card::getRank() {
    return rankToString(r);
}

std::string Card::toString() {
    std::string tempString = "" + getRank() + " of " + getSuit();
    return tempString;
}

int Card::getCardValue() {
    return static_cast<int>(r);
}
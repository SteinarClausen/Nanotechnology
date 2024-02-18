#pragma once

#include <string>

enum class Suit {clubs, diamonds, hearts,spades};

enum class Rank {two = 2, three, four, five, six, seven, eight, nine, ten=10, jack=10, queen=10, king=10, ace=11};

class Card {
    private:
        Suit s;
        Rank r;
    public:
        Card(Suit param1, Rank param2): s(param1), r(param2) {}
        std::string getSuit();
        std::string getRank();
        std::string toString();
        int getCardValue();
};

std::string suitToString(Suit suit);

std::string rankToString(Rank rank);
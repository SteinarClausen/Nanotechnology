#include "Card.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "CardDeck.h"
#include "BlackJack.h"

BlackJack::BlackJack() {
    deck.shuffle();
    playerHand.push_back(deck.drawCard());
    playerHand.push_back(deck.drawCard());
    dealerHand.push_back(deck.drawCard());
    dealerHand.push_back(deck.drawCard());
    playerHandSum = getHandScore(playerHand);
    dealerHandSum = getHandScore(dealerHand);
}

bool BlackJack::isAce(Card card) {
    if (card.getRank() == "Ace" ) {
        return true;
    }
    return false;
}

int BlackJack::getHandScore(std::vector<Card> hand) {
    int aces = 0;
    int handScore = 0;
    for(Card card : hand) {
        if(isAce(card)) {
            aces++;
        }
        handScore += card.getCardValue();
    }
    while (aces > 0) {
        if (handScore > 21) {
            handScore -= 10;
        }
        aces--;
    }
    return handScore;
}

bool BlackJack::askPlayerDrawCard() {
    while (true) {
        std::cout << "Would you like to draw another card? [Y]/[N] ";
        std::string answer;
        std::cin >> answer;
        if ((answer == "Y")||(answer == "y")) {
            return true;
        } else if ((answer == "N")||(answer == "n")) {
            return false;
        }
    }
}

void BlackJack::drawPlayerCard() {
    Card card = deck.drawCard();
    playerHand.push_back(card);
    playerHandSum = getHandScore(playerHand);
}

void BlackJack::drawDealerCard() {
    Card card = deck.drawCard();
    dealerHand.push_back(card);
    dealerHandSum = getHandScore(dealerHand);
}

void BlackJack::playGame() {
    std::cout << "Dealer got " << dealerHand[0].toString() << " as his top card" << std::endl;
    std::cout << "You got ";
    for (Card card: playerHand) {
        std::cout << card.toString();
        if ((card.getRank() != playerHand.back().getRank())||(card.getSuit() != playerHand.back().getSuit())) {
            std::cout << ", ";
        } else {
            std::cout << std::endl;
        }
    }
    std::cout << "Your sum is " << playerHandSum << std::endl;
    bool play = true;
    while (playerHandSum < 21 && play) {
        if (askPlayerDrawCard()) {
            drawPlayerCard();
            std::cout << "You got a " << playerHand.back().toString() << ". Sum is now " << playerHandSum << std::endl;
        } else {
            play = false;
        }
    }
    play = true;
    std::cout << "Dealer also got " << dealerHand.back().toString() << ". Sum is now " << dealerHandSum << std::endl;
    while ((dealerHandSum < 21 && play)) {
        if (playerHandSum > 21) {
            play = false;
        } else if (dealerHandSum < 17) { //Rule, dealer MUST stand if hand sum is 17 or greater, no matter the player cards.
            drawDealerCard();
            std::cout << "Dealer got " << dealerHand.back().toString() << ". Sum is now " << dealerHandSum << std::endl;
        } else {
            play = false;
        }
    }
    if (playerHandSum > 21) {
        std::cout << "Player loses." << std::endl;
    } else if (dealerHandSum > 21) { 
        std::cout << "Player wins." << std::endl;
    } else if (playerHandSum > dealerHandSum) {
        std::cout << "Player wins." << std::endl;
    } else {
        std::cout << "Player loses." << std::endl;
    }
}
//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// This program outputs the message "Hello, World!" to the monitor
#include <string>
#include <map>
#include <iostream>
// #include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "BlackJack.h"

//------------------------------------------------------------------------------'

//oppgave 1 e) Fordel med å bruke enums kan være at det gjør det lettere å dele dem opp men samtidig at man har en gitt tallverdi til hver verdi, det gjør det lettere å dele dem opp.
// C++ programs start by executing the function main
int main() {
    BlackJack b;
    b.playGame();
    return 0;
}

//------------------------------------------------------------------------------

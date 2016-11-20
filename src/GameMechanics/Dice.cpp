//
// Created by dylan on 17/11/2016.
//

#include <cstdlib>
#include "Dice.h"

std::pair<int, int> * GameMechanics::Dice::generateNewDiceRoll() {
    int firstDice = rand() % MAXIMUM_DICE + MINIMUM_DICE;
    int secondDice = rand() % MAXIMUM_DICE + MINIMUM_DICE;
    diceRoll = std::make_pair(firstDice, secondDice);
    return &diceRoll;
}

std::pair<int, int> *GameMechanics::Dice::getCurrentDiceRoll() {
    return &diceRoll;
}

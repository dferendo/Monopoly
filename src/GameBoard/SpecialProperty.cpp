//
// Created by dylan on 16/11/2016.
//

#include "SpecialProperty.h"

GameBoard::SpecialProperty::SpecialProperty(const string &name, double propertyPrice) : Property(name, propertyPrice) {}

void GameBoard::SpecialProperty::setDiceNumber(int diceNumber) {
    SpecialProperty::diceNumber = diceNumber;
}

void GameBoard::SpecialProperty::action(Player::Participant *player, GameMechanics::Game * game) {
    // TODO action
}
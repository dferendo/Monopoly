//
// Created by dylan on 28/11/2016.
//

#include "Mortgage.h"
#include "../Player/Participant.h"

GameBoard::Mortgage::Mortgage(double mortgagePrice) : mortgagePrice(mortgagePrice) {}

bool GameBoard::Mortgage::isPropertyMortgage() const {
    return propertyMortgage;
}

double GameBoard::Mortgage::getMortgagePrice() const {
    return mortgagePrice;
}

void GameBoard::Mortgage::makePropertyMortgage(Player::Participant *participant) {
    participant->getMoney().addBalance(mortgagePrice);
    propertyMortgage = true;
}

void GameBoard::Mortgage::removeMortgage(Player::Participant *participant) {
    participant->getMoney().subtractBalance(mortgagePrice * INTEREST_PERCENTAGE);
    propertyMortgage = false;
}

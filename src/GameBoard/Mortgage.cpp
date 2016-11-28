//
// Created by dylan on 28/11/2016.
//

#include "Mortgage.h"

GameBoard::Mortgage::Mortgage(double mortgagePrice) : mortgagePrice(mortgagePrice) {}

bool GameBoard::Mortgage::isPropertyMortgage() const {
    return propertyMortgage;
}

int GameBoard::Mortgage::getMortgagePrice() const {
    return mortgagePrice;
}

void GameBoard::Mortgage::setPropertyMortgage(bool propertyMortgage) {
    Mortgage::propertyMortgage = propertyMortgage;
}

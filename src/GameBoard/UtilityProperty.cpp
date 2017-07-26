//
// Created by dylan on 16/11/2016.
//

#include "../../include/GameBoard/UtilityProperty.h"
#include "../../include/Exception/NoMoneyException.h"
#include "../../include/GameMechanics/Bankruptcy.h"
using namespace Exception;
using namespace std;

GameBoard::UtilityProperty::UtilityProperty(const string &name, double propertyPrice, double rentCost,
                                            const ColourType &colour, double mortgage)
        : NonUpgradableProperty(name, propertyPrice, rentCost, colour, mortgage) {}

double GameBoard::UtilityProperty::getRentCost(GameMechanics::Game *game) {
    if (checkIfOwnerHasAllSameColour()) {
        return OWNER_OWNS_BOTH_UTILITY_COST * game->getDiceCount();
    }
    return rentCost * game->getDiceCount();
}


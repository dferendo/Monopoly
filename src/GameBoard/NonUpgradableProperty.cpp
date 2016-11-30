//
// Created by dylan on 30/11/2016.
//

#include "Property.h"
#include "NonUpgradableProperty.h"

GameBoard::NonUpgradableProperty::NonUpgradableProperty(const string &name, double propertyPrice, double rentCost,
                                                        const string &colour, double mortgage) : Property(name,
                                                                                                          propertyPrice,
                                                                                                          rentCost,
                                                                                                          colour,
                                                                                                          mortgage) {}
void GameBoard::NonUpgradableProperty::doActionWithoutBeingOnProperty(GameMechanics::Game * game) {
    // The only thing a non upgradable property can do is to be mortgage.
    if (isPropertyMortgage()) {
        removeMortgage(getOwner());
    } else {
        makePropertyMortgage(getOwner());
    }
}

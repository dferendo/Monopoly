//
// Created by dylan on 30/11/2016.
//

#include <sstream>
#include "Property.h"
#include "NonUpgradableProperty.h"

GameBoard::NonUpgradableProperty::NonUpgradableProperty(const string &name, double propertyPrice, double rentCost,
                                                        const Colour &colour, double mortgage) : Property(name,
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

string GameBoard::NonUpgradableProperty::toString(GameBoard::Property &property) {
    stringstream displayProperty;
    displayProperty << "Property name: " << getName();
    displayProperty << "\nProperty Price: " << getPropertyPrice();
    displayProperty << "\nOwner: ";
    if (getOwner() == nullptr) {
        displayProperty << "Banker";
    } else {
        displayProperty << getOwner();
    }
    displayProperty << "\nMortgage value: " << getMortgagePrice();
    displayProperty << "\nColour type: " << Colours::getColourInString(getColour());
    displayProperty << "\nDoes not build houses";
    return displayProperty.str();
}

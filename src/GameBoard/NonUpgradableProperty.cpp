//
// Created by dylan on 30/11/2016.
//

#include <sstream>
#include "../../include/GameBoard/Property.h"
#include "../../include/GameBoard/NonUpgradableProperty.h"
#include "../../include/Exception/PropertyIsAlreadyMortgageException.h"
#include "../../include/Exception/PropertyIsNotMortgagedException.h"
using namespace std;

GameBoard::NonUpgradableProperty::NonUpgradableProperty(const string &name, const double propertyPrice,
                                                        const double rentCost, const ColourType &colour,
                                                        const double mortgage) : Property(name, propertyPrice,
                                                                                          rentCost, colour,
                                                                                          mortgage) {}

void GameBoard::NonUpgradableProperty::doActionWithoutBeingOnProperty(GameMechanics::Game * game) {
    vector<string> displayMenu = {"Display House Details", "Mortgage Property", "Remove Mortgage", "Go Back"};
    int index;

    try {
        Util::displayMenu(displayMenu);
        index = Util::readIntegerWithRange(0, (int) displayMenu.size() - 1);

        switch(index) {
            case 0: {
                cout << toString() << endl;
                break;
            }
            case 1: {
                makePropertyMortgage(getOwner());
                break;
            }
            case 2: {
                removeMortgage(getOwner());
                break;
            }
            default:break;
        }
    } catch (Exception::PropertyIsNotMortgagedException &propertyNotMortgaged) {
        cout << propertyNotMortgaged.message << endl;
    } catch (Exception::PropertyIsAlreadyMortgageException &propertyIsMortgaged) {
        cout << propertyIsMortgaged.message << endl;
    }
}

string GameBoard::NonUpgradableProperty::toString() {
    stringstream displayProperty;
    displayProperty << "Property name: " << getName();
    displayProperty << "\nProperty Price: " << getPropertyPrice();
    displayProperty << "\nOwner: ";
    // If owner is nullptr, that means the banker owns it
    if (getOwner() == nullptr) {
        displayProperty << "Banker";
    } else {
        displayProperty << getOwner()->getName();
    }
    displayProperty << "\nMortgage value: " << getMortgagePrice();
    displayProperty << "\nColour type: " << Colour::getColourInString(getColourType());
    displayProperty << "\nDoes not build houses";
    return displayProperty.str();
}

void GameBoard::NonUpgradableProperty::action(Player::Participant *participant, GameMechanics::Game *game) {
    // Nobody owns the property
    if (getOwner() == nullptr) {
        noOwner(participant, game);
    } else if (!(getOwner() == participant)) {
        // Pay rent
        payRent(participant, game);
    }
}

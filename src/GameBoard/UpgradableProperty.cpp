//
// Created by dylan on 16/11/2016.
//

#include <sstream>
#include "../../include/GameBoard/UpgradableProperty.h"
#include "../../include/Exception/NoHouseException.h"
#include "../../include/Exception/NoMoneyException.h"
#include "../../include/GameMechanics/Bankruptcy.h"
#include "../../include/Exception/PropertyIsNotMortgagedException.h"
#include "../../include/Exception/PropertyIsAlreadyMortgageException.h"

using namespace Exception;
using namespace std;

GameBoard::UpgradableProperty::UpgradableProperty(const string &name, const double propertyPrice, const double rentCost,
                                                  const ColourType &colour, const GameBoard::HousesPrice housesPrice,
                                                  const double mortgage) :
        Property(name, propertyPrice, rentCost, colour, mortgage), housesPrice(housesPrice) {}

string GameBoard::UpgradableProperty::getName() {
    string houseUpgrade;
    // House cannot be mortgage if there are b
    if (isPropertyMortgage()) {
        return Tile::getName() + " - Mortgage";
    }
    for (int i = 0; i < getCurrentHousesBuild(); i++) {
        houseUpgrade += "*";
    }
    return Tile::getName() + houseUpgrade;
}

void GameBoard::UpgradableProperty::action(Player::Participant *participant, GameMechanics::Game * game) {
    if (getOwner() == nullptr) {
        noOwner(participant, game);
    } else if (getOwner() == participant) {
        // Upgrade hotel
        if (checkIfOwnerHasAllSameColour()) {
            addHouseToProperty(participant);
        } else {
            cout << "Upgrading house is currently not available. You do not have all the properties "
                    "of the same colours" << endl;
        }
    } else {
        payRent(participant, game);
    }
}

void GameBoard::UpgradableProperty::addHouseToProperty(Player::Participant *participant) {
    string input;

    if (isPropertyMortgage()) {
        cout << "You have all the same group colours but this property is mortgaged!" << endl;
    } else {
        cout << housesPrice << endl;
        cout << "Want to upgrade house? (Y/n)" << endl;
        getline(cin, input);
        try {
            if (input[0] == 'y' || input[0] == 'Y') {
                int currentHouseBuild = getCurrentHousesBuild();
                // Limit of houses
                if (currentHouseBuild < MAX_HOUSES) {
                    participant->getMoney().subtractBalance(getHousesPrice().getPriceToUpgrade());
                    setCurrentHousesBuild(getCurrentHousesBuild() + 1);
                } else {
                    cout << "Maximum house limit." << endl;
                }
            }
        } catch (NoMoneyException &noMoneyException) {
            cout << noMoneyException.message << " Returning to previous menu." << endl;
        }
    }
}

void GameBoard::UpgradableProperty::removeHouseFromProperty(Player::Participant *participant) {
    double amount;
    string input;
    // Cannot remove house if there are not any build
    if (getCurrentHousesBuild() == 0) {
        throw NoHouseException(this);
    }
    amount = getHousesPrice().getPriceToUpgrade() / 2;
    cout << "Do you really want to remove a house? You will receive half the cost(" << amount
         << ")it took to build it. (Y/n)" << endl;
    getline(cin, input);
    if (input[0] == 'Y' || input[0] == 'y') {
        // Selling house gets half what he paid for building it
        setCurrentHousesBuild(getCurrentHousesBuild() - 1);
        participant->getMoney().addBalance(getHousesPrice().getPriceToUpgrade() / 2);
    }
}

void GameBoard::UpgradableProperty::doActionWithoutBeingOnProperty(GameMechanics::Game *game) {
    // Upgradable property can either build/sell houses or mortgage/unmortgaged property
    vector<string> displayMenu = {"Property Details", "Sell houses", "Add mortgage", "Remove mortgage",
                                  "Return to main menu"};
    int selection;

    Util::displayMenu(displayMenu);
    selection = Util::readIntegerWithRange(0, (int) displayMenu.size() - 1);
    // Can only sell houses, building can only happens when a participant lands on a Tile.
    // If someone wants to build houses without that assumption just implement addHouseToProperty() here.
    try {
        switch (selection) {
            case 0: {
                cout << toString() << endl;
                break;
            }
            case 1: {
                removeHouseFromProperty(getOwner());
                break;
            }
            case 2: {
                makePropertyMortgage(getOwner());
                break;
            }
            case 3: {
                removeMortgage(getOwner());
                break;
            }
            default:break;
        }
    } catch(NoHouseException & exception) {
        cout << exception.message << " Return to menu" << endl;
    } catch (PropertyIsNotMortgagedException &propertyNotMortgaged) {
        cout << propertyNotMortgaged.message << endl;
    } catch (PropertyIsAlreadyMortgageException &propertyIsMortgaged) {
        cout << propertyIsMortgaged.message << endl;
    }
}

double GameBoard::UpgradableProperty::getRentCost(GameMechanics::Game *game) {
    int currentHousesBuild = getCurrentHousesBuild();
    // If no hotel and does not own same colour properties
    if (currentHousesBuild == 0 && !checkIfOwnerHasAllSameColour()) {
        return rentCost;
    } else if (currentHousesBuild == 0) {
        // Owner has same colour properties but no house, thus pay double rent
        cout << "Owner has all " << getColourType() << " properties. Pay double rent!!" << endl;
        return rentCost * 2;
    } else {
        return getHousesPrice().getHouseRent(currentHousesBuild);
    }
}

string GameBoard::UpgradableProperty::toString() {
    stringstream displayProperty;
    displayProperty << "Property name: " << getName();
    displayProperty << "\nProperty Price: " << getPropertyPrice();
    displayProperty << "\nOwner: ";
    if (getOwner() == nullptr) {
        displayProperty << "Banker";
    } else {
        displayProperty << getOwner()->getName();
    }
    displayProperty << "\nMortgage value: " << getMortgagePrice();
    displayProperty << "\nColour type: " << Colour::getColourInString(getColourType());
    displayProperty << "\n" << getHousesPrice();
    return displayProperty.str();
}

void GameBoard::UpgradableProperty::setCurrentHousesBuild(int currentHousesBuild) {
    UpgradableProperty::currentHousesBuild = currentHousesBuild;
}

int GameBoard::UpgradableProperty::getCurrentHousesBuild() const {
    return currentHousesBuild;
}

const GameBoard::HousesPrice &GameBoard::UpgradableProperty::getHousesPrice() const {
    return housesPrice;
}

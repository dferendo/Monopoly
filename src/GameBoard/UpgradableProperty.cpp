//
// Created by dylan on 16/11/2016.
//

#include "UpgradableProperty.h"
#include "../Exception/NoHouseException.h"
#include "../Exception/NoMoneyException.h"
#include "../GameMechanics/Bankruptcy.h"

using namespace Exception;

GameBoard::UpgradableProperty::UpgradableProperty(const string &name, double propertyPrice, double rentCost,
                                                  const Colour &colour, GameBoard::HousesPrice housesPrice, double mortgage) :
        Property(name, propertyPrice, rentCost, colour, mortgage), housesPrice(housesPrice) {}

const GameBoard::HousesPrice &GameBoard::UpgradableProperty::getHousesPrice() const {
    return housesPrice;
}

void GameBoard::UpgradableProperty::action(Player::Participant *player, GameMechanics::Game * game) {
    if (getOwner() == nullptr) {
        noOwner(player, game);
    } else if (getOwner() == player) {
        // Upgrade hotel
        if (checkIfOwnerHasAllSameColour(player, game)) {
            addHouseToProperty(player);
        } else {
            cout << "Upgrading house is currently not available. You do not have all the properties "
                    "of the same colours" << endl;
        }
    } else {
        payRent(player, game);
    }
}

void GameBoard::UpgradableProperty::payRent(Player::Participant *player, GameMechanics::Game * game) {
    double amount = getRentCost(game);
    try {
        player->getMoney().subtractBalance(amount);
        getOwner()->getMoney().addBalance(amount);
    } catch (NoMoneyException & noMoneyException) {
        cout << noMoneyException.message << endl;
        // If player cannot pay debt, he will be declared bankrupt
        bool isPlayerNotBankrupt = noMoneyException.payAmountDue(game, noMoneyException.amountDue, player, getOwner());
        if (!isPlayerNotBankrupt) {
            Bankruptcy::transferProperties(game, player, getOwner());
        }
    }
}

void GameBoard::UpgradableProperty::addHouseToProperty(Player::Participant *player) {
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
                if (currentHouseBuild < MAX_HOUSES) {
                    player->getMoney().subtractBalance(getHousesPrice().getPriceToUpgrade());
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

void GameBoard::UpgradableProperty::removeHouseFromProperty(Player::Participant *player) {
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
        player->getMoney().addBalance(getHousesPrice().getPriceToUpgrade() / 2);
    }
}

int GameBoard::UpgradableProperty::getCurrentHousesBuild() const {
    return currentHousesBuild;
}

void GameBoard::UpgradableProperty::setCurrentHousesBuild(int currentHousesBuild) {
    UpgradableProperty::currentHousesBuild = currentHousesBuild;
}

void GameBoard::UpgradableProperty::doActionWithoutBeingOnProperty(GameMechanics::Game *game) {
    // Upgradable property can either build/sell houses or mortgage/unmortgaged property
    vector<string> displayMenu;

    displayMenu.push_back("Sell houses");
    displayMenu.push_back("Manage mortgage");
    displayMenu.push_back("Return to main menu");

    Util::displayMenu(displayMenu);
    int selection = Util::readIntegerWithRange(0, (int) displayMenu.size() - 1);
    // Can only sell houses, building can only happens when a participant lands on a Tile.
    // If someone wants to build houses without that assumption just implement addHouseToProperty() here.
    try {
        if (selection == 0) {
            removeHouseFromProperty(getOwner());
        } else if (selection == 1) {
            // If property is mortgage, ask to remove it.
            // If property is not mortgage, ask to make house mortgage
            if (isPropertyMortgage()) {
                removeMortgage(getOwner());
            } else {
                makePropertyMortgage(getOwner());
            }
        }
    } catch(NoHouseException & exception) {
        cout << exception.message << " Return to menu" << endl;
    }
}

double GameBoard::UpgradableProperty::getRentCost(GameMechanics::Game *game) {
    int currentHousesBuild = getCurrentHousesBuild();
    // If no hotel and does not own same colour properties
    if (currentHousesBuild == 0 && !checkIfOwnerHasAllSameColour(getOwner(), game)) {
        return rentCost;
    } else if (currentHousesBuild == 0) {
        // Owner has same colour properties but no house, thus pay double rent
        cout << "Owner has all " << getColour() << " properties. Pay double rent!!" << endl;
        return rentCost * 2;
    } else {
        return getHousesPrice().getHousePrice(currentHousesBuild);
    }
}

string GameBoard::UpgradableProperty::toString(GameBoard::Property &property) {
    // TODO
    return nullptr;
}

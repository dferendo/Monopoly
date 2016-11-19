//
// Created by dylan on 16/11/2016.
//

#include "UpgradableProperty.h"

GameBoard::UpgradableProperty::UpgradableProperty(const string &name, double propertyPrice, double rentCost,
                                                  const string &colour, GameBoard::HousesPrice housesPrice) :
        Property(name, propertyPrice, rentCost, colour), housesPrice(housesPrice) {}

bool GameBoard::UpgradableProperty::checkIfUpgradeIsAvailable(Player::Participant *player, GameMechanics::Game *game) {
    return player->getSameGroupColourProperties(getColour()) == game->getGroupColoursSize(getColour());
}

const GameBoard::HousesPrice &GameBoard::UpgradableProperty::getHousesPrice() const {
    return housesPrice;
}

void GameBoard::UpgradableProperty::action(Player::Participant *player, GameMechanics::Game * game) {
    if (getOwner() == nullptr) {
        noOwner(player, game);
    } else if (getOwner()->isEqual(player)) {
        // Upgrade hotel
        if (checkIfUpgradeIsAvailable(player, game)) {
            // TODO upgrade
        } else {
            cout << "Upgrading house is currently not available." << endl;
        }
    } else {
        payRent(player, game);
    }
}

void GameBoard::UpgradableProperty::payRent(Player::Participant *player, GameMechanics::Game * game) {
    double amount;
    // If no hotel
    if (currentHousesBuild == 0) {
        amount = getRentCost();
    } else {
        amount = getHousesPrice().getHousePrice(currentHousesBuild);
    }
    player->getMoney().subtractBalance(amount);
    getOwner()->getMoney().addBalance(amount);
}




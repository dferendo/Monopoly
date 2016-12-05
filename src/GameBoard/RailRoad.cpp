//
// Created by dylan on 19/11/2016.
//

#include "RailRoad.h"
#include "../Exception/NoMoneyException.h"
#include "../GameMechanics/Bankruptcy.h"
#include <math.h>
using namespace Exception;

GameBoard::RailRoad::RailRoad(const string &name, double propertyPrice,
                              double rentCost, const Colour &colour, double mortgage)
        : NonUpgradableProperty(name, propertyPrice, rentCost, colour, mortgage) {}


void GameBoard::RailRoad::action(Player::Participant *player, GameMechanics::Game *game) {
    // Nobody owns the property
    if (getOwner() == nullptr) {
        noOwner(player, game);
    } else if (!(getOwner() == player)) {
        // Pay rent
        payRent(player, game);
    }
}

void GameBoard::RailRoad::payRent(Player::Participant *player, GameMechanics::Game * game) {
    double amount = getRentCost(game);
    try {
        player->getMoney().subtractBalance(amount);
        getOwner()->getMoney().addBalance(amount);
    } catch (NoMoneyException & exception) {
        cout << exception.message << endl;
        // If player cannot pay debt, he will be declared bankrupt
        bool isPlayerNotBankrupt = exception.payAmountDue(game, exception.amountDue, player, getOwner());
        if (!isPlayerNotBankrupt) {
            Bankruptcy::transferProperties(game, player, getOwner());
        }
    }
}

double GameBoard::RailRoad::getRentCost(GameMechanics::Game *game) {
    int numberOfRailRoad = getOwner()->getSameGroupColourPropertiesAmount(getColour());
    cout << "The owner has in total " << numberOfRailRoad << " railroads" << endl;
    // Charge 25 if one owned, 50 if two owned, 100 if three owned, 200 if all owned by the same owner
    return pow(2, (double) numberOfRailRoad - 1) * 25;
}

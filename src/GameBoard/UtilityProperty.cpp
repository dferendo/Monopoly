//
// Created by dylan on 16/11/2016.
//

#include "UtilityProperty.h"
#include "../Exception/NoMoneyException.h"
#include "../GameMechanics/Bankruptcy.h"
using namespace Exception;

GameBoard::UtilityProperty::UtilityProperty(const string &name, double propertyPrice, double rentCost,
                                            const string &colour, double mortgage)
        : NonUpgradableProperty(name, propertyPrice, rentCost, colour, mortgage) {}

void GameBoard::UtilityProperty::action(Player::Participant *player, GameMechanics::Game * game) {
    // Nobody owns the property
    if (getOwner() == nullptr) {
        noOwner(player, game);
    } else if (!getOwner()->isEqual(player)) {
        // Pay rent
        payRent(player, game);
    }
}

void GameBoard::UtilityProperty::payRent(Player::Participant *player, GameMechanics::Game * game) {
    double amount;

    if (isPropertyMortgage()) {
        cout << "Property is mortgage, no rent is due." << endl;
        return;
    }
    amount = getRentCost(game);
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

double GameBoard::UtilityProperty::getRentCost(GameMechanics::Game *game) {
    if (checkIfOwnerHasAllSameColour(getOwner(), game)) {
        return OWNER_OWNS_BOTH_UTILITY * game->getDiceCount();
    }
    return rentCost * game->getDiceCount();
}


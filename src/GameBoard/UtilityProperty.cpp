//
// Created by dylan on 16/11/2016.
//

#include "UtilityProperty.h"
#include "../Exception/NoMoneyException.h"

GameBoard::UtilityProperty::UtilityProperty(const string &name, double propertyPrice, double rentCost,
                                            const string &colour, double mortgage)
        : Property(name, propertyPrice, rentCost, colour, mortgage) {}

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
    amount = game->getDiceCount() * rentCost(player);
    try {
        player->getMoney().subtractBalance(amount);
        getOwner()->getMoney().addBalance(amount);
    } catch (NoMoneyException & noMoneyException) {
        cout << noMoneyException.message << endl;
        // TODO fix this
    }
}

double GameBoard::UtilityProperty::rentCost(Player::Participant *player) {
    if (getOwner()->getSameGroupColourPropertiesAmount("WHITE") == 2) {
        return OWNER_OWNS_BOTH_UTILITY;
    }
    return getRentCost();
}


//
// Created by dylan on 16/11/2016.
//

#include "UtilityProperty.h"

GameBoard::UtilityProperty::UtilityProperty(const string &name, double propertyPrice, double rentCost,
                                            const string &colour) : Property(name, propertyPrice, rentCost, colour) {}

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
    double amount = game->getDiceCount() * rentCost(player);
    player->getMoney().subtractBalance(amount);
    getOwner()->getMoney().addBalance(amount);
}

double GameBoard::UtilityProperty::rentCost(Player::Participant *player) {
    if (getOwner()->getSameGroupColourProperties("WHITE") == 2) {
        return OWNER_OWNS_BOTH_UTILITY;
    }
    return getRentCost();
}


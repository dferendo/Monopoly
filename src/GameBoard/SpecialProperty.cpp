//
// Created by dylan on 16/11/2016.
//

#include "SpecialProperty.h"

GameBoard::SpecialProperty::SpecialProperty(const string &name, double propertyPrice, double rentCost,
                                            const string &colour) : Property(name, propertyPrice, rentCost, colour) {}

void GameBoard::SpecialProperty::action(Player::Participant *player, GameMechanics::Game * game) {
    // Nobody owns the property
    if (getOwner() == nullptr) {
        noOwner(player, game);
    } else if (!getOwner()->isEqual(player)) {
        // Pay rent
        payRent(player, game);
    }
}

void GameBoard::SpecialProperty::payRent(Player::Participant *player, GameMechanics::Game * game) {
    double amount = game->getDiceCount() * getRentCost();
    player->getMoney().subtractBalance(amount);
    getOwner()->getMoney().addBalance(amount);
}


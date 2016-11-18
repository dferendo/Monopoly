//
// Created by dylan on 16/11/2016.
//

#include "UpgradableProperty.h"

GameBoard::UpgradableProperty::UpgradableProperty(const string &name, double propertyPrice, double rentCost,
                                                  string colour) : Property(name, propertyPrice, rentCost),
                                                                   colour(colour) {}

void GameBoard::UpgradableProperty::action(Player::Participant *player, GameMechanics::Game * game) {
    // Nobody owns the property
    if (getOwner() == nullptr) {
        noOwner(player, game);
    } else if (getOwner()->isEqual(player)) {
        // Upgrade hotel
    } else {
        payRent(player);
    }
}
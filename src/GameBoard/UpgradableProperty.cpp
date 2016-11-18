//
// Created by dylan on 16/11/2016.
//

#include "UpgradableProperty.h"

GameBoard::UpgradableProperty::UpgradableProperty(const string &name, double propertyPrice) : Property(name,
                                                                                                       propertyPrice) {}


void GameBoard::UpgradableProperty::action(Player::Participant *player, GameMechanics::Game * game) {
    // TODO
}

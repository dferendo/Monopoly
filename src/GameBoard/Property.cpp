//
// Created by dylan on 16/11/2016.
//

#include "Property.h"
#include "../Player/Participant.h"

GameBoard::Property::Property(const string &name, double propertyPrice) : Tile(name), propertyPrice(propertyPrice) {}


void GameBoard::Property::action(Player::Participant *player, GameMechanics::Game * game) {
    // Nobody owns the property
    if (owner == nullptr) {
        noOwner(player);
    } else if (!owner->isEqual(player)) {
        // Pay rent
    }
}

const Player::Participant* GameBoard::Property::getOwner() const {
    return owner;
}

void GameBoard::Property::setOwner(Player::Participant *owner) {
    Property::owner = owner;
}

void GameBoard::Property::noOwner(Player::Participant *player) {
    vector<string> noOwnerChoice;
    noOwnerChoice.push_back("Buy house");
    noOwnerChoice.push_back("Banker auction house");

    cout << getName() << " is currently on sale!!\nChoices available: " << endl;
    Util::displayMenu(noOwnerChoice);
    int choice = Util::readIntegerWithRange(0, 1);
    if (choice == 0) {
        buyHouse(player);
    } else {
        // TODO auction house
    }
}

void GameBoard::Property::buyHouse(Player::Participant *player) {
    player->getMoney().subtractBalance(propertyPrice);
    player->addParticipantProperty(this);
    setOwner(player);
}

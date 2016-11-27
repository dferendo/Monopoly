//
// Created by dylan on 18/11/2016.
//

#ifndef MONOPOLY_MENUHELPER_H
#define MONOPOLY_MENUHELPER_H

#include <iostream>
#include <vector>
#include "../Player/Participant.h"
#include "../GameBoard/Property.h"
#include "../Exception/NoHousesException.h"

using namespace std;

namespace GameBoard {
    class Property;
}

namespace Util {
    void displayMenu(vector<string> &options);
    void displayPlayers(vector<Player::Participant *> participants);
    void displayNonImprovedHouseForPlayer(Player::Participant *participant, vector<GameBoard::Property *> properties);
    void displayImprovedHouseForPlayer(Player::Participant *participant, vector<GameBoard::Property *> properties);
}
#endif //MONOPOLY_MENUHELPER_H

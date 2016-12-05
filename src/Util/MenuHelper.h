//
// Created by dylan on 18/11/2016.
//

#ifndef MONOPOLY_MENUHELPER_H
#define MONOPOLY_MENUHELPER_H

#include <iostream>
#include <vector>
#include "../Exception/NoPropertyException.h"

using namespace std;

namespace GameBoard {
    class Property;
}

namespace Util {
    void displayMenu(vector<string> &options);
    void displayPlayers(vector<Player::Participant *> participants);
    void displayHouseForPlayer(Player::Participant *participant, vector<GameBoard::Property *> properties);
}
#endif //MONOPOLY_MENUHELPER_H

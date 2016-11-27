//
// Created by dylan on 18/11/2016.
//

#ifndef MONOPOLY_MENUHELPER_H
#define MONOPOLY_MENUHELPER_H

#include <iostream>
#include <vector>
#include "../Player/Participant.h"

using namespace std;

namespace Util {
    void displayMenu(vector<string> &options);
    void displayPlayers(vector<Player::Participant *> participants);
    void displayAllHouseForPlayer(Player::Participant *participant);
}
#endif //MONOPOLY_MENUHELPER_H

//
// Created by dylan on 18/11/2016.
//

#include "MenuHelper.h"

void Util::displayMenu(vector<string> &options) {
    for(std::vector<string>::size_type i = 0; i != options.size(); i++) {
        cout << i << ". " << options[i] << endl;
    }
}

void Util::displayPlayers(vector<Player::Participant *> participants) {
    for (std::vector<string>::size_type i = 0; i != participants.size(); i++) {
        cout << i << ". " << participants[i]->getName() << endl;
    }
}

//
// Created by dylan on 18/11/2016.
//

#include "../Exception/NoHousesException.h"
#include "MenuHelper.h"

void Util::displayMenu(vector<string> &options) {
    for (vector<string>::size_type i = 0; i != options.size(); i++) {
        cout << i << ". " << options[i] << endl;
    }
}

void Util::displayPlayers(vector<Player::Participant *> participants) {
    for (vector<string>::size_type i = 0; i != participants.size(); i++) {
        cout << i << ". " << participants[i]->getName() << endl;
    }
}

void Util::displayAllHouseForPlayer(Player::Participant *participant) {
    vector<GameBoard::Property *> &allProperties = participant->getParticipantProperties();

    if (allProperties.size() == 0) {
        throw NoHousesException(*participant);
    }
    for (vector<GameBoard::Property *>::size_type i = 0; i != allProperties.size(); i++) {
        cout << i << ". " << allProperties[i]->getName() << endl;
    }
}

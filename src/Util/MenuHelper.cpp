//
// Created by dylan on 18/11/2016.
//
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

void Util::displayNonImprovedHouseForPlayer(Player::Participant *participant,
                                            vector<GameBoard::Property *> properties) {
    if (properties.size() == 0) {
        throw NoHousesException(*participant);
    }
    cout << "Displaying all non improved properties " << participant->getName() << " properties. Choice one:" << endl;
    for (vector<GameBoard::Property *>::size_type i = 0; i != properties.size(); i++) {
        cout << i << ". " << properties[i]->getName() << endl;
    }
}

void Util::displayImprovedHouseForPlayer(Player::Participant *participant,
                                           vector<GameBoard::Property *> properties) {
    if (properties.size() == 0) {
        // TODO not throwing good??
        throw NoHousesException(*participant, " has no improved houses!");
    }
    cout << "Displaying all improved properties " << participant->getName() << " properties. Choice one:" << endl;
    for (vector<GameBoard::Property *>::size_type i = 0; i != properties.size(); i++) {
        cout << i << ". " << properties[i]->getName() << endl;
    }
}

void Util::displayAllMortgageProperties(Player::Participant *participant,
                                         vector<GameBoard::Property *> properties) {
    if (properties.size() == 0) {
        // TODO not throwing good??
        throw NoHousesException(*participant, " has no mortgage houses!");
    }
    cout << "Displaying all mortgage properties " << participant->getName() << " properties. Choice one:" << endl;
    for (vector<GameBoard::Property *>::size_type i = 0; i != properties.size(); i++) {
        cout << i << ". " << properties[i]->getName() << endl;
    }
}


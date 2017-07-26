//
// Created by dylan on 18/11/2016.
//
#include "../../include/Util/MenuHelper.h"
#include "../../include/GameBoard/Property.h"
using namespace Exception;
using namespace std;

void Util::displayMenu(vector<string> &options) {
    for (vector<string>::size_type i = 0; i != options.size(); i++) {
        cout << i << ". " << options[i] << endl;
    }
}

void Util::displayParticipants(vector<Player::Participant *> participants) {
    for (vector<Player::Participant *>::size_type i = 0; i != participants.size(); i++) {
        cout << i << ". " << participants[i]->getName() << endl;
    }
}

void Util::displayHousesForParticipant(Player::Participant *participant) {
    vector<GameBoard::Property *> & properties = participant->getParticipantProperties();
    if (properties.size() == 0) {
        throw NoPropertyException(*participant);
    }
    cout << "Displaying all properties " << participant->getName() << " properties. Choice one:" << endl;
    for (vector<GameBoard::Property *>::size_type i = 0; i != properties.size(); i++) {
        cout << i << ". " << properties[i]->getName() << endl;
    }
}

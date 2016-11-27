//
// Created by dylan on 17/11/2016.
//

#include "Participant.h"
#include "../Exception/NoHousesException.h"

Player::Participant::Participant(int participantId, const string &name) : participantId(participantId), name(name) {}

int Player::Participant::getParticipantId() const {
    return participantId;
}

string Player::Participant::getName() {
    return name;
}

Player::Money &Player::Participant::getMoney() {
    return money;
}

vector<GameBoard::Property *> & Player::Participant::getParticipantProperties() {
    return participantProperties;
}

void Player::Participant::addParticipantProperty(GameBoard::Property *property) {
    participantProperties.push_back(property);
}

int Player::Participant::getCurrentPosition() {
    return currentPosition;
}

void Player::Participant::setCurrentPosition(int currentPosition) {
    Participant::currentPosition = currentPosition;
}

bool Player::Participant::isEqual(Player::Participant *participant) {
    return participantId == participant->participantId;
}

int Player::Participant::getSameGroupColourPropertiesAmount(string colourType) {
    int counter = 0;
    for(auto const& property : participantProperties) {
        if (property->getColour() == colourType){
            counter++;
        }
    }
    return counter;
}

vector<GameBoard::Property *> Player::Participant::getGroupColoursProperties(string colourType) {
    vector<GameBoard::Property *> groupColoursProperties;
    for (auto const& property : participantProperties) {
        if (property->getColour() == colourType) {
            groupColoursProperties.push_back(property);
        }
    }
    return groupColoursProperties;
}

void Player::Participant::removeProperty(GameBoard::Property * property) {
    participantProperties.erase(remove(participantProperties.begin(), participantProperties.end(), property),
                                participantProperties.end());
}

vector<GameBoard::Property *> &Player::Participant::getNonImprovedParticipantProperties() {
    vector<GameBoard::Property *> * nonImprovedProperties = new vector<GameBoard::Property *>;
    for (auto &property : participantProperties) {
        if (property->getCurrentHousesBuild() == 0) {
            nonImprovedProperties->push_back(property);
        }
    }
    if (nonImprovedProperties->size() == 0) {
        delete(nonImprovedProperties);
        throw NoHousesException(*this);
    }
    return *nonImprovedProperties;
}

//
// Created by dylan on 17/11/2016.
//

#include "Participant.h"

Player::Participant::Participant(int participantId, const string &name) : participantId(participantId), name(name),
                                                                          money(Money(1500)), currentPosition(0) {}

int Player::Participant::getParticipantId() const {
    return participantId;
}

string Player::Participant::getName() {
    return name;
}

Player::Money & Player::Participant::getMoney() {
    return money;
}

vector<GameBoard::Property *> Player::Participant::getParticipantProperties() {
    return participantProperties;
}

void Player::Participant::addParticipantProperty(GameBoard::Property *property) {
    participantProperties.push_back(property);
}

int Player::Participant::getCurrentPosition() {
    return currentPosition;
}

void Player::Participant::moveCurrentPosition(int currentPosition) {
    Participant::currentPosition += currentPosition;
}

bool Player::Participant::isEqual(Player::Participant *participant) {
    return participantId == participant->participantId;
}

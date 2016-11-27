// Created by dylan on 27/11/2016.
//
//

#ifndef MONOPOLY_NOHOUSESEXCEPTION_H
#define MONOPOLY_NOHOUSESEXCEPTION_H

#include "../Player/Participant.h"

class NoHousesException {
public:
    string message;
    NoHousesException(Player::Participant & participant);
    NoHousesException(Player::Participant & participant, string message);
};


#endif //MONOPOLY_NOHOUSESEXCEPTION_H

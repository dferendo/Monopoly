//
// Created by dylan on 27/11/2016.
//

#include <sstream>
#include "NoHousesException.h"

namespace Exception {
    NoHousesException::NoHousesException(Player::Participant &participant) {
        stringstream messageCompose;
        messageCompose << participant.getName() << " has no houses!";
        message = messageCompose.str();
    }

    NoHousesException::NoHousesException(Player::Participant &participant, string message) {
        stringstream messageCompose;
        messageCompose << participant.getName() << message;
        this->message = messageCompose.str();
    }
}

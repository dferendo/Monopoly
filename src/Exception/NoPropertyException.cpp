//
// Created by dylan on 27/11/2016.
//

#include <sstream>
#include "NoPropertyException.h"

namespace Exception {
    NoPropertyException::NoPropertyException(Player::Participant &participant) {
        stringstream messageCompose;
        messageCompose << participant.getName() << " has no properties!";
        message = messageCompose.str();
    }

    NoPropertyException::NoPropertyException(Player::Participant &participant, string message) {
        stringstream messageCompose;
        messageCompose << participant.getName() << message;
        this->message = messageCompose.str();
    }
}

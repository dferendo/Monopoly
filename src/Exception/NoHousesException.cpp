//
// Created by dylan on 27/11/2016.
//

#include <sstream>
#include "NoHousesException.h"

NoHousesException::NoHousesException(Player::Participant &participant) {
    stringstream messageCompose;
    messageCompose << participant.getName() << " has no houses!";
    message = messageCompose.str();
}
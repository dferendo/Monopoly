//
// Created by dylan on 27/11/2016.
//

#include <sstream>
#include "../../include/Exception/NoPropertyException.h"
using namespace std;

namespace Exception {
    NoPropertyException::NoPropertyException(Player::Participant &participant) {
        stringstream messageCompose;
        messageCompose << participant.getName() << " has no properties!";
        message = messageCompose.str();
    }
}

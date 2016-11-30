// Created by dylan on 27/11/2016.
//
//

#ifndef MONOPOLY_NOHOUSESEXCEPTION_H
#define MONOPOLY_NOHOUSESEXCEPTION_H

#include "../Player/Participant.h"

namespace Exception {
    class NoPropertyException {
    public:
        string message;
        NoPropertyException(Player::Participant &participant);
        NoPropertyException(Player::Participant &participant, string message);
    };
}


#endif //MONOPOLY_NOHOUSESEXCEPTION_H

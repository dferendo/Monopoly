// Created by dylan on 27/11/2016.
//
//

#ifndef MONOPOLY_NOHOUSESEXCEPTION_H
#define MONOPOLY_NOHOUSESEXCEPTION_H

#include "../Player/Participant.h"

namespace Exception {
    class NoPropertyException {
    public:
        std::string message;

        NoPropertyException(Player::Participant &participant);
    };
}


#endif //MONOPOLY_NOHOUSESEXCEPTION_H

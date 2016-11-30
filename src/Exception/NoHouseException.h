//
// Created by dylan on 30/11/2016.
//

#ifndef MONOPOLY_NOHOUSEEXCEPTION_H
#define MONOPOLY_NOHOUSEEXCEPTION_H


#include "../GameBoard/UpgradableProperty.h"

namespace Exception {
    class NoHouseException {
    public:
        string message;
        NoHouseException(GameBoard::UpgradableProperty * property);
    };
}

#endif //MONOPOLY_NOHOUSEEXCEPTION_H

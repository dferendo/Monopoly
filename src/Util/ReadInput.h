//
// Created by dylan on 17/11/2016.
//

#ifndef MONOPOLY_READINPUT_H
#define MONOPOLY_READINPUT_H

#include <iostream>
using namespace std;

namespace Util {
    int readIntegerWithRange(int lowerRange, int upperRange);
    int readPositiveInteger();
    string readString();
}
#endif //MONOPOLY_READINPUT_H

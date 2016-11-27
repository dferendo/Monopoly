//
// Created by dylan on 17/11/2016.
//

#ifndef MONOPOLY_READINPUT_H
#define MONOPOLY_READINPUT_H

#include <iostream>
#include <limits>
using namespace std;

namespace Util {
    int readIntegerWithRange(int lowerRange, int upperRange);
    double readPositiveDouble();
    string readString();
    void pressEnterToContinue();
}
#endif //MONOPOLY_READINPUT_H

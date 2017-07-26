//
// Created by dylan on 17/11/2016.
//

#ifndef MONOPOLY_READINPUT_H
#define MONOPOLY_READINPUT_H

#include <iostream>
#include <limits>

namespace Util {

    /**
     * Reads an integer from a range. The input is taken as a string and the numbers are read. Two exceptions are
     * caught. If the number is out_of_range (3333333333333333333333333333 for example) and invalid_argument
     * which does not accept letters or empty input.
     * @param lowerRange The lower limit.
     * @param upperRange The upper limit.
     * @return A number between the given ranges.
     */
    int readIntegerWithRange(int lowerRange, int upperRange);

    /**
     * Reads an integer greater or equal than 0 and lower or equal than the given limit. Two exceptions are
     * caught. If the number is out_of_range (3333333333333333333333333333 for example) and invalid_argument
     * which does not accept letters or empty input.
     * @param limit The greatest number the user can enter.
     * @return returns a positive double.
     */
    double readPositiveDoubleWithLimit(double limit);

    /**
     * Reads a string, does not accept empty strings.
     * @return A string from user input.
     */
    std::string readString();

    /**
     * Used to pause the program. Ignores every input except '\n'
     */
    void pressEnterToContinue();
}
#endif //MONOPOLY_READINPUT_H

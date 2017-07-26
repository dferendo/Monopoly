//
// Created by dylan on 07/12/2016.
//

#ifndef MONOPOLY_PROPERTYISNOTMORTGAGEDEXCEPTION_H
#define MONOPOLY_PROPERTYISNOTMORTGAGEDEXCEPTION_H

#include <iostream>

namespace Exception {
    class PropertyIsNotMortgagedException {
    public:
        std::string message = "House is not mortgaged!";
    };
}
#endif //MONOPOLY_PROPERTYISNOTMORTGAGEDEXCEPTION_H

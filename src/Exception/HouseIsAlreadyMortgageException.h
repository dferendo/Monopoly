//
// Created by dylan on 28/11/2016.
//

#ifndef MONOPOLY_HOUSEISALREADYMORTGAGEEXCEPTION_H
#define MONOPOLY_HOUSEISALREADYMORTGAGEEXCEPTION_H

#include <iostream>
namespace Exception {
    class HouseIsAlreadyMortgageException {
    public:
        std::string message = "House is already mortgage!";
    };
}


#endif //MONOPOLY_HOUSEISALREADYMORTGAGEEXCEPTION_H

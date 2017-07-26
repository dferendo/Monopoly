//
// Created by dylan on 18/11/2016.
//

#ifndef MONOPOLY_MENUHELPER_H
#define MONOPOLY_MENUHELPER_H

#include <iostream>
#include <vector>
#include "../Exception/NoPropertyException.h"

namespace Util {

    /**
     * Displays a menu by looping through a vector and adding their position according to the vector.
     * @param options The options available.
     */
    void displayMenu(std::vector<std::string> &options);

    /**
     * Displays the participants by looping through a vector and adding their position according to the vector.
     * @param participants The participants given.
     */
    void displayParticipants(std::vector<Player::Participant *> participants);

    /**
     * Displays all properties owned by a participant. An exception is thrown is the participant does not
     * have any property.
     * @param participant The participant that wants to see his property.
     */
    void displayHousesForParticipant(Player::Participant *participant);
}
#endif //MONOPOLY_MENUHELPER_H

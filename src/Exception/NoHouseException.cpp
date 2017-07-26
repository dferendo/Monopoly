//
// Created by dylan on 30/11/2016.
//

#include <sstream>
#include "../../include/Exception/NoHouseException.h"

Exception::NoHouseException::NoHouseException(GameBoard::UpgradableProperty * property) {
    std::stringstream messageCompose;
    messageCompose << property->getName() << " has no houses! * indicates that the property has houses!";
    message = messageCompose.str();
}

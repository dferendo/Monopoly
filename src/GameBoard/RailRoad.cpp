//
// Created by dylan on 19/11/2016.
//

#include "../../include/GameBoard/RailRoad.h"
#include "../../include/Exception/NoMoneyException.h"
#include "../../include/GameMechanics/Bankruptcy.h"
#include <math.h>
using namespace Exception;
using namespace std;

GameBoard::RailRoad::RailRoad(const string &name, const double propertyPrice,
                              const double rentCost, const ColourType &colour, const double mortgage)
        : NonUpgradableProperty(name, propertyPrice, rentCost, colour, mortgage) {}


double GameBoard::RailRoad::getRentCost(GameMechanics::Game *game) {
    int numberOfRailRoad = getOwner()->getSameGroupColourPropertiesAmount(getColourType());
    cout << "The owner has in total " << numberOfRailRoad << " railroads" << endl;
    // Charge 25 if one owned, 50 if two owned, 100 if three owned, 200 if all owned by the same owner
    return pow(2, (double) numberOfRailRoad - 1) * 25;
}

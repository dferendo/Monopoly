//
// Created by dylan on 19/11/2016.
//

#include "HousesPrice.h"

namespace GameBoard {
    HousesPrice::HousesPrice(int priceToUpgrade, int oneHouse, int secondHouse, int thirdHouse,
                                        int fourHouse) : priceToUpgrade(priceToUpgrade), oneHouse(oneHouse),
                                                         secondHouse(secondHouse), thirdHouse(thirdHouse),
                                                         fourHouse(fourHouse) {}

    int HousesPrice::getHousePrice(int numberOfHouse) const {
        if (numberOfHouse == 1) {
            return oneHouse;
        } else if (numberOfHouse == 2) {
            return secondHouse;
        } else if (numberOfHouse == 3) {
            return thirdHouse;
        } else {
            return fourHouse;
        }
    }

    // Print class information
    std::ostream &operator<<(std::ostream &stream, const HousesPrice &housesPrice) {
        return stream << "Price of house starting from one house: " << housesPrice.oneHouse << ", "
                      << housesPrice.secondHouse << ", " << housesPrice.thirdHouse << ", "
                      << housesPrice.fourHouse << ". Price to upgrade: " << housesPrice.priceToUpgrade << endl;
    }

    int HousesPrice::getPriceToUpgrade() const {
        return priceToUpgrade;
    }
}
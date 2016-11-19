//
// Created by dylan on 19/11/2016.
//

#ifndef MONOPOLY_HOUSES_H
#define MONOPOLY_HOUSES_H

#include <iostream>
using namespace std;

namespace GameBoard {
    class HousesPrice {
    private:
        // To access private variable
        friend std::ostream& operator<<(std::ostream& stream, const HousesPrice& housesPrice);
        int priceToUpgrade;
        int oneHouse;
        int secondHouse;
        int thirdHouse;
        int fourHouse;
    public:
        HousesPrice(int priceToUpgrade, int oneHouse, int secondHouse, int thirdHouse, int fourHouse);
        int getHousePrice(int numberOfHouse) const;
        int getPriceToUpgrade() const;
    };
}
#endif //MONOPOLY_HOUSES_H

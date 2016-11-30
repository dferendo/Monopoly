//
// Created by dylan on 29/11/2016.
//

#include "SellingBuilding.h"
using namespace Exception;

void GameMechanics::SellingBuilding::sellBuilding(Participant *participant) {
    string input;
    std::vector<GameBoard::Property *> nonImprovedProperties;
    try {
        participant->getImprovedParticipantProperties(nonImprovedProperties);
        Util::displayImprovedHouseForPlayer(participant, nonImprovedProperties);
        int sellBuildingPropertyIndex = Util::readIntegerWithRange(0, (int) nonImprovedProperties.size() - 1);
        GameBoard::Property * property = nonImprovedProperties[sellBuildingPropertyIndex];
        // If building has houses, it is an upgradeableProperty
        GameBoard::UpgradableProperty * upgradableProperty = dynamic_cast<GameBoard::UpgradableProperty *> (property);
        // Check if dynamic cast did not fail
        if (upgradableProperty) {

        } else {
            // TODO check with JP for this thing
        }
    } catch (NoPropertyException &exception) {
        cout << exception.message << " Returning to previous menu." << endl;
    }
}

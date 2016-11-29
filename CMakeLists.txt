cmake_minimum_required(VERSION 3.6)
project(Monopoly)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")

set(SOURCE_FILES src/Main.cpp src/Exception/NoMoneyException.h)
add_executable(Monopoly ${SOURCE_FILES} src/Main.cpp
        src/Exception/HouseIsMortgageException.h
        src/GameBoard/Tile.cpp src/GameBoard/Tile.h src/GameBoard/Parking.cpp
        src/GameBoard/Parking.h src/GameBoard/Xorti.cpp src/GameBoard/Xorti.h
        src/GameBoard/Property.cpp src/GameBoard/Property.h src/GameBoard/UtilityProperty.cpp src/GameBoard/UtilityProperty.h src/GameBoard/UpgradableProperty.cpp src/GameBoard/UpgradableProperty.h src/Monopoly.cpp src/Monopoly.h src/GameBoard/Tax.cpp src/GameBoard/Tax.h src/Player/Participant.cpp src/Player/Participant.h src/Player/Money.cpp src/Player/Money.h src/Util/ReadInput.cpp src/Util/ReadInput.h src/GameMechanics/Dice.cpp src/GameMechanics/Dice.h src/Util/MenuHelper.cpp src/Util/MenuHelper.h src/GameMechanics/Game.cpp src/GameMechanics/Game.h src/GameMechanics/FillBoard.cpp src/GameMechanics/FillBoard.h src/GameBoard/RailRoad.cpp src/GameBoard/RailRoad.h src/GameBoard/HousesPrice.cpp src/GameBoard/HousesPrice.h src/Exception/NoHousesException.cpp src/Exception/NoHousesException.h src/GameMechanics/Trade.cpp src/GameMechanics/Trade.h src/GameBoard/Mortgage.cpp src/GameBoard/Mortgage.h src/GameMechanics/Move.cpp src/GameMechanics/Move.h src/Exception/HouseIsAlreadyMortgageException.h src/Exception/NoMoneyException.cpp)
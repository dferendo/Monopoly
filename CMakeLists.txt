cmake_minimum_required(VERSION 3.6)
project(Monopoly)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")

set(HEADER_FILES
        include/Monopoly.h
        include/Exception/NoHouseException.h
        include/Exception/NoMoneyException.h
        include/Exception/NoPropertyException.h
        include/Exception/PropertyIsAlreadyMortgageException.h
        include/Exception/PropertyIsNotMortgagedException.h
        include/GameBoard/Colour.h
        include/GameBoard/HousesPrice.h
        include/GameBoard/Mortgage.h
        include/GameBoard/NonUpgradableProperty.h
        include/GameBoard/Parking.h
        include/GameBoard/Property.h
        include/GameBoard/RailRoad.h
        include/GameBoard/Tax.h
        include/GameBoard/Tile.h
        include/GameBoard/UpgradableProperty.h
        include/GameBoard/UtilityProperty.h
        include/GameBoard/Xorti.h
        include/GameMechanics/Bankruptcy.h
        include/GameMechanics/Dice.h
        include/GameMechanics/FillBoard.h
        include/GameMechanics/Game.h
        include/GameMechanics/Move.h
        include/GameMechanics/Trade.h
        include/Player/Money.h
        include/Player/Participant.h
        include/Util/MenuHelper.h
        include/Util/ReadInput.h
        )

set(SOURCE_FILES
        src/Main.cpp
        src/Monopoly.cpp
        src/Exception/NoHouseException.cpp
        src/Exception/NoMoneyException.cpp
        src/Exception/NoPropertyException.cpp
        src/GameBoard/Colour.cpp
        src/GameBoard/HousesPrice.cpp
        src/GameBoard/Mortgage.cpp
        src/GameBoard/NonUpgradableProperty.cpp
        src/GameBoard/Parking.cpp
        src/GameBoard/Property.cpp
        src/GameBoard/RailRoad.cpp
        src/GameBoard/Tax.cpp
        src/GameBoard/Tile.cpp
        src/GameBoard/UpgradableProperty.cpp
        src/GameBoard/UtilityProperty.cpp
        src/GameBoard/Xorti.cpp
        src/GameMechanics/Bankruptcy.cpp
        src/GameMechanics/Dice.cpp
        src/GameMechanics/FillBoard.cpp
        src/GameMechanics/Game.cpp
        src/GameMechanics/Move.cpp
        src/GameMechanics/Trade.cpp
        src/Player/Money.cpp
        src/Player/Participant.cpp
        src/Util/MenuHelper.cpp
        src/Util/ReadInput.cpp
        )


add_executable(Monopoly ${HEADER_FILES} ${SOURCE_FILES})
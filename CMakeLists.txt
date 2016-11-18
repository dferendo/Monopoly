cmake_minimum_required(VERSION 3.6)
project(Monopoly)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/Main.cpp)
add_executable(Monopoly ${SOURCE_FILES} src/Main.cpp src/GameBoard/Tile.cpp src/GameBoard/Tile.h src/GameBoard/CornerTiles.h src/GameBoard/Parking.cpp src/GameBoard/Parking.h src/GameBoard/Go.cpp src/GameBoard/Go.h src/GameBoard/EmptyTile.h src/GameBoard/Xorti.cpp src/GameBoard/Xorti.h src/GameBoard/Property.cpp src/GameBoard/Property.h src/GameBoard/SpecialProperty.cpp src/GameBoard/SpecialProperty.h src/GameBoard/UpgradableProperty.cpp src/GameBoard/UpgradableProperty.h src/Monopoly.cpp src/Monopoly.h src/GameBoard/Tax.cpp src/GameBoard/Tax.h src/Player/Participant.cpp src/Player/Participant.h src/Player/Money.cpp src/Player/Money.h src/Util/ReadInput.cpp src/Util/ReadInput.h src/GameMechanics/Dice.cpp src/GameMechanics/Dice.h src/Util/MenuHelper.cpp src/Util/MenuHelper.h src/GameMechanics/Game.cpp src/GameMechanics/Game.h src/GameMechanics/FillBoard.cpp src/GameMechanics/FillBoard.h)
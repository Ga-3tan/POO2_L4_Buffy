cmake_minimum_required(VERSION 3.19)
project(POO2_L4_Buffy)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wconversion -pedantic")

add_executable(POO2_L4_Buffy main.cpp GameLogic/Field.cpp GameLogic/Field.h GameLogic/Entities/Buffy.cpp GameLogic/Entities/Buffy.h GameLogic/Entities/Humanoid.cpp GameLogic/Entities/Humanoid.h GameLogic/Entities/Vampire.cpp GameLogic/Entities/Vampire.h Utils/Coordinate.cpp Utils/Coordinate.h GameLogic/Actions/Action.cpp GameLogic/Actions/Action.h Game.cpp Game.h GameLogic/Entities/Human.h GameLogic/Entities/Human.cpp GameLogic/Actions/Move.cpp GameLogic/Actions/Move.h GameLogic/Actions/Kill.cpp GameLogic/Actions/Kill.h GameLogic/Actions/Convert.h GameLogic/Actions/Convert.cpp Utils/ConsoleManager.h Utils/ConsoleManager.cpp)

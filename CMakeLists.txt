cmake_minimum_required(VERSION 3.19)
project(POO2_L4_Buffy)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wconversion -pedantic")

add_executable(POO2_L4_Buffy main.cpp GameLogic/Field.cpp GameLogic/Field.h Entities/Buffy.cpp Entities/Buffy.h Entities/Humanoid.cpp Entities/Humanoid.h Entities/Vampire.cpp Entities/Vampire.h Utils/Coordinate.cpp Utils/Coordinate.h GameLogic/Action.cpp GameLogic/Action.h Game.cpp Game.h GameLogic/Move.cpp GameLogic/Move.h GameLogic/Kill.cpp GameLogic/Kill.h)
cmake_minimum_required(VERSION 3.13)
project(the_garden)

set(CMAKE_CXX_STANDARD 14)

add_executable(the_garden main.cpp PlantsInTheGarden.cpp PlantsInTheGarden.h Trees.cpp Trees.h Flowers.cpp Flowers.h TheActualGarden.cpp TheActualGarden.h)
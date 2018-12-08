cmake_minimum_required(VERSION 3.12)
project(v2cpse2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(C:/Users/djrel/Downloads/SFML-2.5.1/include)
include_directories(week1)

add_executable(v2cpse2
        week2/action.hpp
        week2/ball.cpp
        week2/ball.hpp
        week2/scherm_object.hpp
        week2/main.cpp
        week2/rectangle.cpp
        week2/rectangle.hpp
        )

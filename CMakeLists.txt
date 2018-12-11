cmake_minimum_required(VERSION 3.12)
project(v2cpse2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(C:/Users/djrel/Downloads/SFML-2.5.1/include)
include_directories(week3)

add_executable(v2cpse2
        week3/action.hpp
        week3/ball.cpp
        week3/ball.hpp
        week3/scherm_object.hpp
        week3/main.cpp
        week3/rectangle.cpp
        week3/rectangle.hpp
        week3/factory.hpp
        week3/line.hpp
        week3/line.cpp
        week3/factory_exceptions.hpp
        week3/image.hpp
        )

cmake_minimum_required(VERSION 3.12)
project(v2cpse2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(C:/Users/djrel/Downloads/SFML-2.5.1/include)
include_directories(C:/Users/djrel/Downloads/boost_1_69_0)
include_directories(week5)

file(GLOB tic_tac_toe_SRC
        "week5/*.hpp"
        "week5/*.cpp"
        )
file(GLOB SFML
        "week5/sfml/*.hpp"
        "week5/sfml/*.cpp")
add_executable(v2cpse2-cli
        ${tic_tac_toe_SRC} week5/cli/main.cpp
        )

add_executable(v2cpse2-sfml
        ${tic_tac_toe_SRC} ${SFML}
        )
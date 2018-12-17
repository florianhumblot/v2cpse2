cmake_minimum_required(VERSION 3.12)
project(v2cpse2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(C:/Users/djrel/Downloads/SFML-2.5.1/include)
include_directories(C:/Users/djrel/Downloads/boost_1_69_0)
include_directories(week5)

file(GLOB tic_tac_toe_SRC
        "week2/*.hpp"
        "week2/*.cpp"
        )

add_executable(v2cpse2
        ${tic_tac_toe_SRC}
        )

cmake_minimum_required(VERSION 3.24)
project(advent_of_code_2022)

set(CMAKE_CXX_STANDARD 17)

Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.0.1 # or a later release
)
FetchContent_MakeAvailable(Catch2)

add_executable(puzzle
        main.cpp Puzzle.h)

add_executable(tests tests.cpp Puzzle.h)
target_link_libraries(tests
        PRIVATE Catch2::Catch2WithMain)

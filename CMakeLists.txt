cmake_minimum_required(VERSION 3.14)

project(BracketBalance LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)
include(FetchContent)

FetchContent_Declare(
    Catch2
    URL https://github.com/catchorg/Catch2/archive/refs/tags/v2.13.10.zip
)

FetchContent_MakeAvailable(Catch2)

add_library(bracket_balance bracket_balance.cpp)
target_include_directories(bracket_balance PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(bracket_tests tests.cpp)
target_link_libraries(bracket_tests PRIVATE
    bracket_balance
    Catch2::Catch2
)

add_test(NAME bracket_tests COMMAND bracket_tests)
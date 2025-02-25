cmake_minimum_required(VERSION 3.20)

project(TICTACTOE)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

set (SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Window.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ClearButton/ClearButton.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Field/Field.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/TurnWindow/TurnWindow.cpp
)

set (HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/Window.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ClearButton/ClearButton.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Field/Field.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/TurnWindow/TurnWindow.hpp
)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_executable(TICTACTOE ${SOURCES} ${HEADERS})

target_link_libraries(TICTACTOE sfml-system sfml-window sfml-graphics)

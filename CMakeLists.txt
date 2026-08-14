cmake_minimum_required(VERSION 3.20)

project(eStone C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(SDL3 CONFIG REQUIRED COMPONENTS SDL3)

add_executable(eStone
    src/main.c
    src/game.c
    src/util.c
    src/bot.c
    src/window.c
)

target_include_directories(eStone PRIVATE headers)

target_link_libraries(eStone PRIVATE SDL3::SDL3)
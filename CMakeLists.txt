cmake_minimum_required(VERSION 2.8.9)
project(thermostat)


include_directories(src)


file(GLOB sources src/*.c)

set(PROJECT_SOURCES ${sources})

add_executable(${CMAKE_PROJECT_NAME}.elf ${PROJECT_SOURCES})








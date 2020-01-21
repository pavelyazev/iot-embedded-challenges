cmake_minimum_required(VERSION 2.8.9)
project(thermostat)

set(CMAKE_TOOLCHAIN_FILE stm32.cmake)

set(LIBOPENCM3_PATH "libopencm3")

set(CMAKE_TOOLCHAIN_FILE stm32.cmake)

include_directories(${LIBOPENCM3_PATH}/include)
link_directories(${LIBOPENCM3_PATH}/lib)

set(PROJECT_LINK_LIBS libopencm3_stm32f4.a)



include_directories(src)


file(GLOB sources src/*.c)

set(PROJECT_SOURCES ${sources})

add_executable(${CMAKE_PROJECT_NAME}.elf ${PROJECT_SOURCES})

target_link_libraries(${CMAKE_PROJECT_NAME}.elf ${PROJECT_LINK_LIBS})


set(CMAKE_EXE_LINKER_FLAGS "-T${CMAKE_CURRENT_SOURCE_DIR}/stm32_flash.ld ${CMAKE_EXE_LINKER_FLAGS}")


add_custom_command(TARGET ${CMAKE_PROJECT_NAME}.elf POST_BUILD COMMAND ${CMAKE_OBJCOPY} ARGS -Oihex ${CMAKE_PROJECT_NAME}.elf ${CMAKE_PROJECT_NAME}.hex)
add_custom_command(TARGET ${CMAKE_PROJECT_NAME}.elf POST_BUILD COMMAND ${CMAKE_OBJCOPY} ARGS -Obinary ${CMAKE_PROJECT_NAME}.elf ${CMAKE_PROJECT_NAME}.bin)






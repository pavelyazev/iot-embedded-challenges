
This project is presumed to build by the following toolchain 
https://launchpad.net/gcc-arm-embedded/+announcement/15345

As a hardware abstraction layer the libopencm3 library was chosen.
https://github.com/libopencm3/libopencm3

This library was build separately in advance. 
Finally only header files and the library for linking were added into project tree.

The target MCU is STM32F4XX.

CMSIS-RTOS abstraction layer is used just to make code more visual.
But it is not the best option because its API is limited.



To build project:

Update stm32.cmake file with proper path to toolchane

mkdir build
cd build
cmake -G "Unix Makefiles" ..
make

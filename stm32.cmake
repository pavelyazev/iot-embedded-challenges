if(WIN32)
set(TOOLCHAIN_DIR "D:/GNU Tools Arm Embedded/9 2019-q4-major")
set(TOOLCHAIN_BIN_DIR ${TOOLCHAIN_DIR}/bin)
else()

endif()
#set(TOOLCHAIN_INC_DIR ${TOOLCHAIN_DIR}/arm-none-eabi/include)
#set(TOOLCHAIN_LIB_DIR ${TOOLCHAIN_DIR}/arm-none-eabi/lib)


set(CMAKE_SYSTEM_NAME      Generic)
set(CMAKE_SYSTEM_VERSION   1)
set(CMAKE_SYSTEM_PROCESSOR arm-none-eabi)

#
# which compilers to use for C and C++
#
if(WIN32)
set(CMAKE_C_COMPILER       ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-gcc.exe CACHE INTERNAL "gcc")
set(CMAKE_CXX_COMPILER     ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-g++.exe CACHE INTERNAL "g++")
set(CMAKE_ASM_COMPILER     ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-as.exe CACHE INTERNAL "as")
set(CMAKE_OBJCOPY     	   ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-objcopy.exe CACHE INTERNAL "objcopy")
set(CMAKE_OBJDUMP     	   ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-objdump.exe CACHE INTERNAL "objdump")
else()
set(CMAKE_C_COMPILER       ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-gcc CACHE INTERNAL "gcc")
set(CMAKE_CXX_COMPILER     ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-g++ CACHE INTERNAL "g++")
set(CMAKE_ASM_COMPILER     ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-as CACHE INTERNAL "as")
set(CMAKE_OBJCOPY     	   ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-objcopy CACHE INTERNAL "objcopy")
set(CMAKE_OBJDUMP     	   ${TOOLCHAIN_BIN_DIR}/arm-none-eabi-objdump CACHE INTERNAL "objdump")
endif()


SET(CMAKE_C_FLAGS "--specs=nosys.specs -mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -Wall -ffunction-sections -g -O0 -D__FPU_USED -DSTM32F4" CACHE INTERNAL "c compiler flags")
SET(CMAKE_CXX_FLAGS "--specs=nosys.specs -mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -fno-builtin -Wall -ffunction-sections -g -O0 -D__FPU_USED -DSTM32F4" CACHE INTERNAL "cxx compiler flags")
SET(CMAKE_ASM_FLAGS "-mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard" CACHE INTERNAL "asm compiler flags")
SET(CMAKE_EXE_LINKER_FLAGS "-mthumb -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -Wall -g -nostartfiles -Wl,-Map=link.map -O0 -Wl,--gc-sections" CACHE INTERNAL "exe link flags")


SET(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_LIBC_DIR} CACHE INTERNAL "cross root directory")
SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM BOTH CACHE INTERNAL "")
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY CACHE INTERNAL "")
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY CACHE INTERNAL "")




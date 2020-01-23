
This project is presumed to build by the following toolchain 
https://launchpad.net/gcc-arm-embedded/+announcement/15345

As a hardware abstraction layer the libopencm3 library was chosen.
https://github.com/libopencm3/libopencm3

This library was build separately in advance. 
Finally only header files and the library for linking were added into project tree.

The target MCU is STM32F4XX.

CMSIS-RTOS abstraction layer is used just to make code more visual.


To build project:

Update stm32.cmake file with proper path to toolchain

mkdir build
cd build
cmake -G "Unix Makefiles" ..
make

The project is split into files in accordance with the functional purpose.
The main logic is situated in the controller.c file.
In intitialization part a task, a message queue and a timer are created.
Event based approach is used. So when something happens in the system controller
task gets notification via the message queue.

For example, timer sends periodic notifications to poll temperature sensor.
When this polling is finished controller sends a notifications itself to perform
a regularion cycle.

Currently a relay regulation is inplemented. The measured temperature is compared with
Min/Max temperature boundaries and a decision is made to close or open the valve.

The controller thread also receives notifications from a communication interface 
(file ci.c in the ci folder) to update the Min/Max temperature boundaries. 

The communication interface is responsible to interract with external equipment.
It is presumed that some frame based protocol is used. A frame may have header part,
payload part, data integrity part and some ending part. So the tasks of communication interface
are getting raw data from some physical interface (like UART), frame extracting and decoding and
notification the controll task about incomming command.

The communication interface also performs sending messages from control part. 
The communication interface is implemented as a task with a its own message queue. 

A physical communication interface is presented by a data link abstraction. 










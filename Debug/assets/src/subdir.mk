################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../assets/src/ball.cpp \
../assets/src/enemy.cpp \
../assets/src/game.cpp \
../assets/src/main.cpp \
../assets/src/player.cpp 

OBJS += \
./assets/src/ball.o \
./assets/src/enemy.o \
./assets/src/game.o \
./assets/src/main.o \
./assets/src/player.o 

CPP_DEPS += \
./assets/src/ball.d \
./assets/src/enemy.d \
./assets/src/game.d \
./assets/src/main.d \
./assets/src/player.d 


# Each subdirectory must supply rules for building sources it contributes
assets/src/%.o: ../assets/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/lepley/Desktop/Apps/c++/MyGame/assets/headers" -I"/home/lepley/Desktop/Apps/c++/MyGame/assets/fonts" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



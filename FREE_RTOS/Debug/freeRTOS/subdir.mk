################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../freeRTOS/croutine.c \
../freeRTOS/heap_1.c \
../freeRTOS/list.c \
../freeRTOS/port.c \
../freeRTOS/queue.c \
../freeRTOS/tasks.c \
../freeRTOS/timers.c 

OBJS += \
./freeRTOS/croutine.o \
./freeRTOS/heap_1.o \
./freeRTOS/list.o \
./freeRTOS/port.o \
./freeRTOS/queue.o \
./freeRTOS/tasks.o \
./freeRTOS/timers.o 

C_DEPS += \
./freeRTOS/croutine.d \
./freeRTOS/heap_1.d \
./freeRTOS/list.d \
./freeRTOS/port.d \
./freeRTOS/queue.d \
./freeRTOS/tasks.d \
./freeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
freeRTOS/%.o: ../freeRTOS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



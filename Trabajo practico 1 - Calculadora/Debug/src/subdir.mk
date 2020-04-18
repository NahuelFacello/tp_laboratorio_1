################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Trabajo\ practico\ 1\ -\ Calculadora.c 

OBJS += \
./src/Trabajo\ practico\ 1\ -\ Calculadora.o 

C_DEPS += \
./src/Trabajo\ practico\ 1\ -\ Calculadora.d 


# Each subdirectory must supply rules for building sources it contributes
src/Trabajo\ practico\ 1\ -\ Calculadora.o: ../src/Trabajo\ practico\ 1\ -\ Calculadora.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Trabajo practico 1 - Calculadora.d" -MT"src/Trabajo\ practico\ 1\ -\ Calculadora.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



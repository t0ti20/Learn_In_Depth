################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Application.c \
../DC_Motor.c \
../Main.c \
../Ultra_Sonic.c 

C_DEPS += \
./Application.d \
./DC_Motor.d \
./Main.d \
./Ultra_Sonic.d 

OBJS += \
./Application.o \
./DC_Motor.o \
./Main.o \
./Ultra_Sonic.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean--2e-

clean--2e-:
	-$(RM) ./Application.d ./Application.o ./DC_Motor.d ./DC_Motor.o ./Main.d ./Main.o ./Ultra_Sonic.d ./Ultra_Sonic.o

.PHONY: clean--2e-


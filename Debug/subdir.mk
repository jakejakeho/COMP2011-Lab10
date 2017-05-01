################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../FBIArray.cpp \
../MediaArray.cpp \
../Person.cpp \
../PersonPosition.cpp \
../RussianArray.cpp \
../lab10-main.cpp \
../lab9-solution.cpp 

OBJS += \
./FBIArray.o \
./MediaArray.o \
./Person.o \
./PersonPosition.o \
./RussianArray.o \
./lab10-main.o \
./lab9-solution.o 

CPP_DEPS += \
./FBIArray.d \
./MediaArray.d \
./Person.d \
./PersonPosition.d \
./RussianArray.d \
./lab10-main.d \
./lab9-solution.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



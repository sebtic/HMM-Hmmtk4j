################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/main/native/Backward.cpp \
../src/main/native/BaumWelch.cpp \
../src/main/native/BaumWelchWithWeightedObservations.cpp \
../src/main/native/FastForward.cpp \
../src/main/native/FastForwardWithWeightedObservations.cpp \
../src/main/native/Forward.cpp \
../src/main/native/Gradient.cpp \
../src/main/native/LabelledTraining.cpp \
../src/main/native/MaximalMutualInformation.cpp \
../src/main/native/SegmentalKMeans.cpp \
../src/main/native/Viterbi.cpp 

OBJS += \
./src/main/native/Backward.o \
./src/main/native/BaumWelch.o \
./src/main/native/BaumWelchWithWeightedObservations.o \
./src/main/native/FastForward.o \
./src/main/native/FastForwardWithWeightedObservations.o \
./src/main/native/Forward.o \
./src/main/native/Gradient.o \
./src/main/native/LabelledTraining.o \
./src/main/native/MaximalMutualInformation.o \
./src/main/native/SegmentalKMeans.o \
./src/main/native/Viterbi.o 

CPP_DEPS += \
./src/main/native/Backward.d \
./src/main/native/BaumWelch.d \
./src/main/native/BaumWelchWithWeightedObservations.d \
./src/main/native/FastForward.d \
./src/main/native/FastForwardWithWeightedObservations.d \
./src/main/native/Forward.d \
./src/main/native/Gradient.d \
./src/main/native/LabelledTraining.d \
./src/main/native/MaximalMutualInformation.d \
./src/main/native/SegmentalKMeans.d \
./src/main/native/Viterbi.d 


# Each subdirectory must supply rules for building sources it contributes
src/main/native/%.o: ../src/main/native/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



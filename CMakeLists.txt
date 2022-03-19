cmake_minimum_required(VERSION 3.19)
project(ProiectOOP)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProiectOOP main.cpp Vehicle.cpp Vehicle.h UtilityVehicle.cpp UtilityVehicle.h Car.cpp Car.h
        FileRepository.cpp FileRepository.h Repository.cpp Repository.h TestVehicle.cpp TestVehicle.h
        ValidationException.h VehicleValidator.cpp VehicleValidator.h CarValidator.cpp CarValidator.h
        TestVehicleValidator.cpp TestVehicleValidator.h TestCar.cpp TestCar.h TestUtilityVehicle.cpp
        TestUtilityVehicle.h UtilityVehicleValidator.cpp UtilityVehicleValidator.h RepositoryException.h
        TestRepository.cpp TestRepository.h FileRepositoryException.h Utils.cpp Utils.h TestFileRepository.cpp TestFileRepository.h)
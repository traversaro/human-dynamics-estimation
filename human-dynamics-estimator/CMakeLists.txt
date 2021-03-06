cmake_minimum_required(VERSION 3.0)

project(human-dynamics-estimator CXX)

## Find packages
find_package(YARP REQUIRED)
find_package(iDynTree REQUIRED)
find_package(Eigen3 REQUIRED)

## Include directories
include_directories(SYSTEM
                    ${YARP_INCLUDE_DIRS}
                    ${iDynTree_INCLUDE_DIRS}
                    ${EIGEN3_INCLUDE_DIRS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/HumanDynamicsEstimator.cpp 
            ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

set(HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/HumanDynamicsEstimator.h)

## Declare a C++ executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

## Specify targets for the linkage
target_link_libraries(${PROJECT_NAME} ${YARP_LIBRARIES}
                                      ${iDynTree_LIBRARIES}
                                      human-forces-provider-data)

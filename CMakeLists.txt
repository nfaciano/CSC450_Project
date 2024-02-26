cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(CSC450_PROJECT VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define CSC450LIB_USE_SOURCE to indicate building from source
add_definitions(-DCSC450LIB_USE_SOURCE=1)

# Add the calc_lib library
add_library(calc_lib STATIC
${PROJECT_SOURCE_DIR}/csc450lib/calc/Development/Source/domainOfDefinition.cpp
${PROJECT_SOURCE_DIR}/csc450lib/calc/Development/Source/Function1D.cpp
${PROJECT_SOURCE_DIR}/csc450lib/calc/Development/Source/PolynomialFunction1D.cpp

${PROJECT_SOURCE_DIR}/csc450lib/calc/Development/Source/BisectionSolver1D.cpp
${PROJECT_SOURCE_DIR}/csc450lib/calc/Development/Source/NewtonRaphsonSolver1D.cpp
${PROJECT_SOURCE_DIR}/csc450lib/calc/Development/Source/SecantSolver1D.cpp



${PROJECT_SOURCE_DIR}/csc450lib/random/Development/Source/CSC450Exception.cpp
${PROJECT_SOURCE_DIR}/csc450lib/random/Development/Source/BallSimulation.cpp
${PROJECT_SOURCE_DIR}/csc450lib/random/Development/Source/Surface.cpp
${PROJECT_SOURCE_DIR}/csc450lib/random/Development/Source/ball.cpp




)


# Include directories for the library
target_include_directories(calc_lib PUBLIC 
    "${PROJECT_SOURCE_DIR}/csc450lib/calc/SDK/Headers"
    "${PROJECT_SOURCE_DIR}/csc450lib/calc/Development/Source"
    "${PROJECT_SOURCE_DIR}/csc450lib/calc/SDK/Demos"
    "${PROJECT_SOURCE_DIR}/csc450lib/random/SDK/Headers"



)

# Add the main executable
add_executable(main_project ${PROJECT_SOURCE_DIR}/csc450lib/random/SDK/Demos/main.cpp)

# Link the library with the main executable
target_link_libraries(main_project PRIVATE calc_lib)

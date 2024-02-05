cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(CSC450_PROJECT VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the calc_lib library
add_library(calc_lib STATIC
    calc/Development/Source/DomainOfDefinition.cpp
    calc/Development/Source/Function1D.cpp
)

# Include directories for the library
target_include_directories(calc_lib PUBLIC 
    "${PROJECT_SOURCE_DIR}/calc/SDK/Headers"
    "${PROJECT_SOURCE_DIR}/calc/Development/Source"
)

# Add the main executable
add_executable(main_project calc/Development/Projects/main.cpp)

# Link the library with the main executable
target_link_libraries(main_project PRIVATE calc_lib)

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
${PROJECT_SOURCE_DIR}/csc450lib/linalg/Development/Source/FunctionND.cpp
${PROJECT_SOURCE_DIR}/csc450lib/linalg/Development/Source/GroundFunction.cpp
${PROJECT_SOURCE_DIR}/csc450lib/linalg/Development/Source/Optimizer1D_gss.cpp
${PROJECT_SOURCE_DIR}/csc450lib/linalg/Development/Source/Optimizer1D_parabolic.cpp
${PROJECT_SOURCE_DIR}/csc450lib/linalg/Development/Source/Function1DfromND.cpp
${PROJECT_SOURCE_DIR}/csc450lib/linalg/Development/Source/Optimizer1D.cpp
${PROJECT_SOURCE_DIR}/csc450lib/linalg/Development/Source/Optimizer1D_steepestDescent.cpp



)


# Include directories for the library
target_include_directories(calc_lib PUBLIC 
    "${PROJECT_SOURCE_DIR}/csc450lib/calc/SDK/Headers"
    "${PROJECT_SOURCE_DIR}/csc450lib/calc/Development/Source"
    "${PROJECT_SOURCE_DIR}/csc450lib/calc/SDK/Demos"
    "${PROJECT_SOURCE_DIR}/csc450lib/random/SDK/Headers"
    "${PROJECT_SOURCE_DIR}/csc450lib/linalg/SDK/Headers"
    "${PROJECT_SOURCE_DIR}/csc450lib/linalg/Development/Source"
    "${PROJECT_SOURCE_DIR}/csc450lib/linalg/SDK/Demos"



)
# Find Doxygen Package
find_package(Doxygen)
if(DOXYGEN_FOUND)
    # Specify where the Doxyfile is located
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)

    # Optionally specify the output directory for Doxygen
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/docs)

    # Note: Do not need to modify the Doxyfile, as Doxygen will use the one provided

    # Add custom target to run Doxygen when asked
    add_custom_target(doc ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_IN}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
else()
    message(STATUS "Doxygen not found, not adding 'doc' target")
endif()
# Add the main executable
add_executable(main_project ${PROJECT_SOURCE_DIR}/csc450lib/linalg/SDK/Demos/distanceToM1Demo.cpp)

# Link the library with the main executable
target_link_libraries(main_project PRIVATE calc_lib)
# Find Doxygen Package



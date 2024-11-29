cmake_minimum_required(VERSION 3.10)

# Set the project name
project(EquationEvaluator)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(EquationEvaluator
    main.cpp
    Equation.cpp
    Number.cpp
    Operator.cpp
    Parenthesis.cpp
)

# Include directories
target_include_directories(EquationEvaluator PUBLIC "${PROJECT_SOURCE_DIR}")
cmake_minimum_required(VERSION 3.10)

# project name and version
project(tutorial VERSION 1.0)

# configure a header file to pass the version number to the source code
configure_file(tutorial_config.h.in tutorial_config.h)

# specify the C++ standard

## method 1: (not work)
# set(CXX_STANDARD 11)
# set(CXX_STANDARD_REQUIRED ON)

## method 2: (work)
# add_compile_options("-std=c++11")

## method 3: (work)
# add_definitions("-std=c++11")

## method 4: (work)
if (CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "-std=c++11")
  # message(STATUS "optional: -std=c++11")
endif(CMAKE_COMPILER_IS_GNUCXX)

# add the executable
add_executable(tutorial tutorial.cc)

target_include_directories(tutorial PUBLIC "${PROJECT_BINARY_DIR}")
cmake_minimum_required(VERSION 3.10)

# project name and version
project(tutorial VERSION 1.0)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

# configure a header file to pass some of the CMake settings to the source code
configure_file(tutorial_config.h.in tutorial_config.h)

# specify the C++ standard
add_compile_options("-std=c++11")

if (USE_MYMATH)
  # add the mathlib library
  add_subdirectory(mathlib)
  list(APPEND EXTRA_LIBS mathlib)
endif()

# add the executable
add_executable(tutorial tutorial.cc)

target_link_libraries(tutorial PUBLIC ${EXTRA_LIBS})

target_include_directories(tutorial PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          )

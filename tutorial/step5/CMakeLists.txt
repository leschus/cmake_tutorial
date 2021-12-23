cmake_minimum_required(VERSION 3.10)

# project name and version
project(tutorial VERSION 1.0)

option(USE_MYMATH "Use tutorial provided math implementation" ON)

# configure a header file to pass some of the CMake settings to the source code
configure_file(tutorial_config.h.in tutorial_config.h)

# specify the C++ standard
add_compile_options("-std=c++11")

# set install path
set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/out")

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

install(TARGETS tutorial DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/tutorial_config.h"
        DESTINATION include)


enable_testing()

# does the application run
add_test(NAME Runs COMMAND tutorial 25)

# does the usage message work?
add_test(NAME VersionInfo COMMAND tutorial)
set_tests_properties(VersionInfo
  PROPERTIES PASS_REGULAR_EXPRESSION "Version [0-9].[0-9]"
  )

# define a function to simplify adding tests
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()

# do a bunch of result based tests
do_test(tutorial 4 "Square .*: 2")
do_test(tutorial 9 "Square .*: 3")
do_test(tutorial 5 "Square .*: 2.236")
do_test(tutorial 7 "Square .*: 2.645")
do_test(tutorial 25 "Square .*: 5")
do_test(tutorial 0.0001 "Square .*: 0.01")
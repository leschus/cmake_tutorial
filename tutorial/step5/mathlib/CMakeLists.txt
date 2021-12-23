add_library(mathlib mysqrt.cc)

# 任何需要链接mathlib库的用户均需要包含mathlib库的头文件所在的目录, 除了mathlib自身(因为
# mathlib的源文件和头文件处于同一目录下)
# 因此这里使用INTERFACE
target_include_directories(mathlib
                          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# does this system provide the log and exp function?
include(CheckSymbolExists)
check_symbol_exists(log "math.h" HAVE_LOG)
check_symbol_exists(exp "math.h" HAVE_EXP)
if (NOT (HAVE_LOG AND HAVE_EXP))
  unset(HAVE_LOG)
  unset(HAVE_EXP)
  set(CMAKE_REQUIRED_LIBRARIES "m")
  check_symbol_exists(log "math.h" HAVE_LOG)
  check_symbol_exists(exp "math.h" HAVE_EXP)
  if (HAVE_LOG AND HAVE_EXP)
    target_link_libraries(mathlib PRIVATE m)
  endif()
endif()

if (HAVE_LOG AND HAVE_EXP)
  message(STATUS "use log() and exp()")
  target_compile_definitions(mathlib
                            PRIVATE "HAVE_LOG" "HAVE_EXP")
endif()

install(TARGETS mathlib DESTINATION lib)
install(FILES mysqrt.h DESTINATION include)
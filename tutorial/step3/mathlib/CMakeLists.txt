add_library(mathlib mysqrt.cc)

# 任何需要链接mathlib库的用户均需要包含mathlib库的头文件所在的目录, 除了mathlib自身(因为
# mathlib的源文件和头文件处于同一目录下)
# 因此这里使用INTERFACE
target_include_directories(mathlib
                          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
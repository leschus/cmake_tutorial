添加版本号时, `project(xxx VERSION 1.0)`将`1`绑定到了变量`xxx_VERSION_MAJOR`, 将`0`绑定到了变量`xxx_VERSION_MINOR`. 在xxx_config.h.in中, `@xxx_VERSION_MAJOR@`和`@xxx_VERSION_MINOR@`将分别替换为对应的变量值.

低版本的编译器在编译使用了c++11特性的源文件时, 需要添加`-std=c++11`编译选项. 在CMakeLists.txt中, 显式指定编译时启用该选项的方式有多种, 已在文件中给出. 其中使用`CMAKE_CXX_STANDARD`指定版本的方法不知为何不奏效. (注意: 测试时, 为了看出效果, 需要将mingw g++版本降低, 例如版本4.9.0, 因为高版本(如8.1.0)即使不添加该编译选项也能编译通过)
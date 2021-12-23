#include <iostream>
#include <string>

#include "tutorial_config.h"


int main(int argc, char** argv) {
  std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
            << Tutorial_VERSION_MINOR << std::endl;
  std::cout << "Hello, world!" << std::endl;

  if (argc >= 2) {
    const double input_value = std::stod(argv[1]);
    std::cout << "The number is: " << input_value << std::endl;
  }
}
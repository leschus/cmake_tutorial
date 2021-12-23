#include <iostream>
#include <string>

#include <cmath>

#include "tutorial_config.h"

#ifdef USE_MYMATH
#include "mysqrt.h"
#endif // USE_MYMATH


int main(int argc, char** argv) {
  std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
            << Tutorial_VERSION_MINOR << std::endl;
  std::cout << "Hello, world!" << std::endl;

  if (argc >= 2) {
    const double input_value = std::stod(argv[1]);
    std::cout << "The number is: " << input_value << std::endl;
#ifdef USE_MYMATH
    std::cout << "Square root of the number is: " << mysqrt(input_value)
              << std::endl;
#else
    std::cout << "Square root of the number is: " << sqrt(input_value)
              << std::endl;
#endif // USE_MYMATH
  }
}
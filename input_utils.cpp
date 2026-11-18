#include "input_utils.h"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace lab4 {

int ReadInt(std::string_view prompt, int min_value, int max_value) {
  while (true) {
    std::cout << prompt;

    std::string line;
    if (!std::getline(std::cin, line)) {
      throw std::runtime_error("Input stream was closed");
    }

    std::istringstream input(line);
    int value = 0;
    std::string extra;
    if ((input >> value) && !(input >> extra) && value >= min_value &&
        value <= max_value) {
      return value;
    }

    std::cout << "Ошибка: введите целое число от " << min_value << " до "
              << max_value << ".\n";
  }
}

}  

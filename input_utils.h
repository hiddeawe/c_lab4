#ifndef LAB4_VARIANT7_INPUT_UTILS_H_
#define LAB4_VARIANT7_INPUT_UTILS_H_

#include <string_view>

namespace lab4 {

int ReadInt(std::string_view prompt, int min_value, int max_value);

}  

#endif  
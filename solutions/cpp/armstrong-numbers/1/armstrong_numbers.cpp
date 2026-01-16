#include "armstrong_numbers.h"
#include <string>
#include <cmath>

namespace armstrong_numbers {

bool is_armstrong_number(int number){
    std::string s_number = std::to_string(number);
    int result{0};
    for(char c : s_number){
        result += static_cast<int>(pow((c - '0'), s_number.size()));
    }
    return (result == number);
}

}  // namespace armstrong_numbers

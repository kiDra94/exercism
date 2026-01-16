#include "reverse_string.h"
#include <string>

namespace reverse_string {

// TODO: add your solution here
std::string reverse_string(std::string text){
    std::string result;
    std::copy(text.rbegin(), text.rend(), std::back_inserter(text));
    return result;
}
}  // namespace reverse_string

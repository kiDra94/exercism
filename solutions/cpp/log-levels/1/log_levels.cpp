#include <string>

namespace log_line {
std::string message(std::string line) {
    std::string original_message{line};
    int starting_index = original_message.find(':') + 2;
    return original_message.substr(starting_index);
}

std::string log_level(std::string line) {
    std::string original_message{line};
    int ending_index = original_message.find(']') -1;
    return original_message.substr(1, ending_index);
}

std::string reformat(std::string line) {
    return message(line) + " (" + log_level(line) + ")";
}
}  // namespace log_line

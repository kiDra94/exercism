#include "atbash_cipher.h"
#include <cctype>  // for std::isalpha, std::isdigit
#include <string>

namespace atbash_cipher {

const std::string plain{"abcdefghijklmnopqrstuvwxyz"};
const std::string cipher{"zyxwvutsrqponmlkjihgfedcba"};

std::string encode(std::string text) {
    std::string result;
    int count = 0;
    size_t index = 0;  // Loop index

    while (index < text.size()) {
        char c = text[index];

        if (std::isalpha(c)) {
            c = std::tolower(c);  // Convert to lowercase
            size_t pos = plain.find(c);  // Find index in plain alphabet
            result += cipher[pos];       // Get corresponding cipher character
            count++;
        } else if (std::isdigit(c)) {
            result += c; // Keep numbers unchanged
            count++;
        }

        // Add space every 5 characters
        if (count % 5 == 0 && count > 0) {
            result += ' ';
        }

        index++;
    }

    // Remove trailing space if added
    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;
}

std::string decode(std::string text) {
    std::string result;
    size_t index = 0;  // Loop index

    while (index < text.size()) {
        char c = text[index];

        if (std::isalpha(c)) {
            c = std::tolower(c);
            size_t pos = cipher.find(c);  // Find index in cipher alphabet
            result += plain[pos];         // Get corresponding plain character
        } else if (std::isdigit(c)) {
            result += c; // Keep numbers unchanged
        }

        index++;
    }

    return result;
}

}  // namespace atbash_cipher

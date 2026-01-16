#include "atbash_cipher.h"
#include <string>
namespace atbash_cipher {

const std::string plain{"abcdefghijklmnopqrstuvwxyz"};
const std::string cipher{"zyxwvutsrqponmlkjihgfedcba"};

std::string encode(std::string text){
    std::string result{""};
    unsigned short index{0};
    size_t cnt{0};
    while (text[index]){
        unsigned char c = text[index];
        if(std::isalpha(c)){
            c = std::tolower(c);
            size_t position_of_c = plain.find(c);
            result += cipher[position_of_c];
            cnt++;
        }else if(std::isdigit(c)){
            result += c;
            cnt++;
        }else if(!std::isalpha(c) || !std::isdigit(c)){
            index++;
            continue;
        }
        index++;
        if(cnt > 0 && cnt % 5 == 0){
            result += " ";
        }
    }
    if(!result.empty() && result.back() == ' '){
        result.pop_back();
    }
    return result;
}

std::string decode(std::string text){
    std::string result{""};
    unsigned short index{0};
    while (text[index]){
        unsigned char c = text[index];
        if(std::isalpha(c)){
            c = std::tolower(c);
            size_t position_of_c = cipher.find(c);
            result += plain[position_of_c];
        }else if(std::isdigit(c)){
            result += c;
        }else if(std::isspace(c)){
            index++;
            continue;
        }
        index++;;
    }
    return result;
}
}  // namespace atbash_cipher

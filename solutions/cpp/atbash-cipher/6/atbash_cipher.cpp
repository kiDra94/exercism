#include "atbash_cipher.h"
#include <string>
namespace atbash_cipher {
std::string plain{"abcdefghijklmnopqrstuvwxyz"};
std::string cipher{"zyxwvutsrqponmlkjihgfedcba"};
// TODO: add your solution here
std::string encode(std::string text){
    std::string result{""};
    unsigned short index{0};
    size_t cnt{0};
    while (text[index]){
        char c = text[index];
        if(std::isalpha(c)){
            size_t position_of_c = plain.find(c);
            result += cipher[position_of_c];
            cnt++;
        }else if(std::isdigit(c)){
            result += c;
            cnt++;
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
        char c = text[index];
        if(std::isalpha(c)){
            size_t position_of_c = cipher.find(c);
            result += plain[position_of_c];
        }else if(std::isdigit(c)){
            result += c;
        }
        index++;;
    }
    return text;
}
}  // namespace atbash_cipher

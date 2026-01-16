#include "atbash_cipher.h"
#include <string>
namespace atbash_cipher {

const std::string cipher{"zyxwvutsrqponmlkjihgfedcba"};
//TO DO: implement function to use instande of while lopps in encode and decode
// TO DO: use for i in text, it is faster
std::string encode(std::string text){
    std::string result{""};
    std::size_t index{0};
    std::size_t cnt{0};
    while (text[index]){
        unsigned char c = text[index];
        if(std::isalpha(c)){
            c = std::tolower(c);
            result += 2*'a' + (25 - c);
            cnt++;
        }else if(std::isdigit(c)){
            result += c;
            cnt++;
        }else {
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
    std::size_t index{0};
    while (text[index]){
        unsigned char c = text[index];
        if(std::isalpha(c)){
            c = std::tolower(c);
            result += 2*'a' + (25 - c);
        }else if(std::isdigit(c)){
            result += c;
        }else {
            index++;
            continue;
        }
        index++;;
    }
    return result;
}
}  // namespace atbash_cipher

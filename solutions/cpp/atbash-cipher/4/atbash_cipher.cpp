#include "atbash_cipher.h"
#include <string>
namespace atbash_cipher {

// TODO: add your solution here
std::string encode(std::string text){
    std::string result{""};
    unsigned short index{0};
    while (text[index]){
        char c = text[index];
        size_t cnt{0};
        if(std::isalpha(c)){
            size_t position_of_c = plain.find(c);
            result += cipher[position_of_c];
            cnt++;
        }else if(std::isdigit(c)){
            result += c;
            cnt++;
        }
        index++;
        if(cnt > 0 && cnt%5==0){
            result += " ";
        }
    }
    return result;
}

std::string decode(std::string text){
    std::string result{""};
    unsigned short index{0};
    while (text[index]){
        if(result.size() >= 5 || result.size()%5==0){
            result += atbash_cipher::plain[text.find(text[index])];
        }else {
            result += " ";
        }
        index++;
    }
    return result;
}
}  // namespace atbash_cipher

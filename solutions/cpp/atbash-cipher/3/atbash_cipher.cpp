#include "atbash_cipher.h"
#include <string>
namespace atbash_cipher {

// TODO: add your solution here
std::string encode(std::string text){
    std::string result{""};
    unsigned short index{0};
    while (text[index]){
        if(result.size() >= 5 || result.size()%5==0){
            result += " ";
        }else {
            result += atbash_cipher::cipher[text.find(text[index])];
        }
        index++;
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

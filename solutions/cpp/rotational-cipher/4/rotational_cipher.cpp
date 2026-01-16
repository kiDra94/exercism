#include "rotational_cipher.h"
#include <string>

namespace rotational_cipher {

std::string rotate(std::string text, int root){
    std::string result{""};
    for(char c: text){
        if(std::isalpha(c)){
        if(c >= 'a' && c <= 'z'){
            if(c + root <= 'z'){
            result += c + root;
        }else{
            result += c + root - 'z' - 1 + 'a';
        }
        }else if(c >= 'A' && c <= 'Z'){
                 if(c + root <= 'Z'){
            result += c + root;
        }else{
            result += c + root - 'z' - 1 + 'A';
        }
        }
    }else{
        result += c;
    }
    }

    return result;
}

}  // namespace rotational_cipher

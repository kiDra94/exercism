#include "rotational_cipher.h"
#include <string>

namespace rotational_cipher {

std::string rotate(std::string text, int root){
    std::string result{""};
    for(char c: text){
        if(std::isalpha(c)){
        if(c + root <= 'z'){
            result += c + root;
        }else{
            result += c + root - 'z' - 1 + 'a';
        }
    }else{
        result += c;
    }
    }

    return result;
}

}  // namespace rotational_cipher

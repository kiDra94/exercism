#include "rotational_cipher.h"
#include <string>

namespace rotational_cipher {

std::string rotate(std::string text, int root){
    std::string result{""};
    for(char c: text){
        if(c + root < 'z'){
            result += c + root;
        }else{
            result += c + root - 'z' - 1 + 'a';
        }
    }

    return result;
}

}  // namespace rotational_cipher

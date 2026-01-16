#include "atbash_cipher.h"
#include <string>
namespace atbash_cipher {

std::string atbash_logic(std::string text, bool is_encode){
    std::string result{""};
    std::size_t cnt{0};
    for(char c : text){
        if(std::isalpha(c)){
            c = std::tolower(c);
            result += 2*'a' + (25 - c);
            cnt++;
        }else if(std::isdigit(c)){
            result += c;
            cnt++;
        }else {
            continue;
        }
        if(is_encode && cnt > 0 && cnt % 5 == 0){
            result += " ";
        }
    }
    if(is_encode && !result.empty() && result.back() == ' '){
        result.pop_back();
    }
    return result;
}

std::string encode(std::string text){
    return atbash_logic(text, true);
}

std::string decode(std::string text){
    return atbash_logic(text, false);
}
}  // namespace atbash_cipher

#include "hexadecimal.h"
#include <string>
#include <cctype>
#include <cmath>

namespace hexadecimal {

    bool is_valid(std::string number){
        for(char c : number){
            if(!std::isdigit(c) && !(c >= 'a' && c <= 'f')) return false;
        }
        return true;
    }

    int convert(std::string number){
        if(!is_valid(number)) return 0;
        int result{0};
        for(int i = number.size() - 1; i >= 0; i--){
            if(std::isdigit(number[i])){
                result += (number[i] - '0') * pow(16, number.size() - i -1);
            }else {
                result += ((number[i] -87) - '0') * pow(16, number.size() - i -1);
            }
        }

        return result;
    }

}  // namespace hexadecimal

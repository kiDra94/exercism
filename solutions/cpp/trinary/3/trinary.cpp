#include "trinary.h"
#include <string>
#include <cmath>

namespace trinary {

bool is_valid(std::string number){
    for(char c: number){
        if(c != '0' && c != '1' && c != '2'){
            return false;
        }
    }
    return true;
}

int to_decimal(std::string number)
{
    int result{0};
    if(!is_valid(number)){
        return 0;
    }
    for(size_t i = 0; i < number.size(); i++){
        result += (number[i]- '0') * static_cast<int>(std::pow(3, number.size()-i-1));
    }
    return result;
}


}  // namespace trinary

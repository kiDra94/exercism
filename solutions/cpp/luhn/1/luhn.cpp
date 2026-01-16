#include "luhn.h"
#include <string>

namespace luhn {

    std::string simplify(std::string sin){
        std::string result{""};
        for(char c: sin){
            if(std::isdigit(c)) result += c;
        }
        return result;
    }

    bool valid(std::string sin){
        std::string simplified = simplify(sin);
        bool is_valid{true};
        int result{0};
        if(simplified.size() <= 1) is_valid = false;
        for(int i = simplified.size() - 2; i >= 0; i -= 2){
            int helper = (simplified[i] - '0') * 2;
            if(helper > 9) result += helper -9;
            result += helper;
        }
        if(result%10 == 0) is_valid = true;
        return is_valid;
    }

}  // namespace luhn

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

    std::string double_second(std::string sin){
        std::string simplified = simplify(sin);
        for(int i = simplified.size() - 2; i >= 0; i -= 2){
            int helper = (simplified[i] - '0') * 2;
            if(helper > 9) simplified[i] += helper -9;
            simplified[i] += helper;
        }
        return simplified;
    }

    bool has_forbidden_char(std::string sin){
        for(char c: sin){
            if(!std::isalpha(c) || !std::isdigit(c) || c != ' '){
                return false;
            }
        }
        return true;
    }

    bool valid(std::string sin){
        std::string doubled_simplified = double_second(sin);
        bool is_valid{true};
        int result{0};
        if(doubled_simplified.size() <= 1) return false;
        if(has_forbidden_char(sin) == false) return false;
        for(char c: doubled_simplified){
            result += c - '0';
        }
        if(result%10 == 0) is_valid = true;
        return is_valid;
    }

}  // namespace luhn

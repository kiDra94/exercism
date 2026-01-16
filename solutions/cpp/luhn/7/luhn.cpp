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
            if(helper > 9) helper -= 9;
            simplified[i] = helper = '0';
        }
        return simplified;
    }

    bool has_forbidden_char(std::string sin){
        for(char c: sin){
            if(!std::isdigit(c) || c != ' '){
                return true;
            }
        }
        return false;
    }

    bool valid(std::string sin){
        if(has_forbidden_char(sin)) return false;
        std::string doubled_simplified = double_second(sin);
        if(doubled_simplified.size() <= 1) return false;
        int result{0};
        for(char c: doubled_simplified){
            result += c - '0';
        }
        return (result % 10 == 0);
    }

}  // namespace luhn

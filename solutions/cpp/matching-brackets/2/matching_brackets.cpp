#include "matching_brackets.h"
#include <vector>
#include <string>

namespace matching_brackets {
    bool check ( std::string brck ) {

        std::vector<char> helper{};
        for(auto &ch : brck) {
            switch(ch) {
                case '(':
                case '[':
                case '{':
                    helper.push_back(ch);
                    break;
                case ')':
                    if(helper.empty() || helper.back() != '(') return false;
                    helper.pop_back();
                    break;
                case ']':
                    if(helper.empty() || helper.back() != '[') return false;
                    helper.pop_back();
                    break;
                case '}':
                    if(helper.empty() || helper.back() != '{') return false;
                    helper.pop_back();
                    break;
            }
        }
        return helper.empty();
    }

}  // namespace matching_brackets

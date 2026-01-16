#if !defined(LUHN_H)
#define LUHN_H
#include <string>

namespace luhn {

bool valid(std::string sin);
std::string simplify(std::string simplified);
std::string double_second(std::string sin);
bool has_forbidden_char(std::string sin);

}  // namespace luhn

#endif  // LUHN_H

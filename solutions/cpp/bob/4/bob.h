#if !defined(BOB_H)
#define BOB_H
#include <string>

namespace bob {

std::string hey(std::string text);
bool is_allcaps(std::string text);
bool is_question(std::string text);
bool is_silenc(std::string text);

}  // namespace bob

#endif  // BOB_H

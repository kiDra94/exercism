#include "bob.h"
#include <string>

namespace bob {

bool is_allcaps(std::string text){
    for(char c: text){
        if(!std::isupper(c)) return false;
    }
    return true;
}
bool is_question(std::string text){
    if(text[text.size() - 1] == '?') return true;
    return false;
}
bool is_silenc(std::string text){
    if(text.size() < 1) return false;
    for(char c: text){
        if(c != ' ') return false;
    }
    return true;
}

std::string hey(std::string text){
    if(is_allcaps(text) && is_question(text)) return "Calm down, I know what I'm doing!";
    else if(is_allcaps(text)) return "Whoa, chill out!";
    else if(is_question(text)) return "Sure.";
    else if(is_silenc(text)) return "Fine. Be that way!";
    return "Whatever.";
}
}  // namespace bob

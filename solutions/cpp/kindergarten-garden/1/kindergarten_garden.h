#pragma once
#include <string>
#include <array>

namespace kindergarten_garden {

enum class Plants {
    clover,
    grass,
    violets,
    radishes,
    wrong_plant
};

inline Plants char_to_plant(char c){
    switch(c){
        case 'C':
            return Plants::clover;
            break;
        case 'G':
            return Plants::grass;
            break;
        case 'V':
            return Plants::violets;
            break;
        case 'R':
            return Plants::radishes;
            break;
    }
    return Plants::wrong_plant;
}

std::array<kindergarten_garden::Plants, 4> plants(std::string plants, std::string child);

}  // namespace kindergarten_garden

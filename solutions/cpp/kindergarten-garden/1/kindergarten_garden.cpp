#include "kindergarten_garden.h"

namespace kindergarten_garden {

std::array<kindergarten_garden::Plants, 4> plants(std::string plants, std::string child){
int child_index = (child[0] - 'A') * 2;
int second_row_start = plants.find('\n') + 1 + child_index;

std::array<Plants, 4> result;
result[0] = char_to_plant(plants[child_index]);
result[1] = char_to_plant(plants[child_index + 1]);
result[2] = char_to_plant(plants[second_row_start]);
result[3] = char_to_plant(plants[second_row_start + 1]);

return result;
}

}  // namespace kindergarten_garden

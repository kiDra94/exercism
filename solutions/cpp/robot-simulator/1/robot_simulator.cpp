#include "robot_simulator.h"
#include <utility>
#include <string>

namespace robot_simulator {

void Robot::turn_right() {
    bearing_ = static_cast<Bearing>((static_cast<int>(bearing_) + 1) % 4);
}

void Robot::turn_left() {
    bearing_ = static_cast<Bearing>((static_cast<int>(bearing_) + 3) % 4);
}

void Robot::advance() {
    switch(bearing_) {
        case Bearing::NORTH:
            position_.second += 1;
            break;
        case Bearing::EAST:
            position_.first += 1;
            break;
        case Bearing::SOUTH:
            position_.second -= 1;
            break;
        case Bearing:: WEST:
            position_.first -= 1;
            break;
    };
};

void Robot::execute_sequence(std::string seq) {
    for(char c : seq) {
      switch(c) {
          case 'R':
              turn_right();
              break;
          case 'L':
              turn_left();
              break;
          case 'A':
              advance();
              break;
        };
    };
};


}  // namespace robot_simulator

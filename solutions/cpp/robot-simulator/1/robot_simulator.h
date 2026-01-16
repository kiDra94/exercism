#pragma once
#include <utility>
#include <string>

namespace robot_simulator {

enum class Bearing{
    NORTH,
    EAST,
    SOUTH,
    WEST,
};

class Robot {
public:
    Robot() = default;
    Robot(std::pair<int, int> pos) : position_(pos) {}
    Robot(std::pair<int, int> pos, Bearing bearing) : position_(pos), bearing_(bearing) {}
    std::pair<int, int> get_position() const { return position_; }
    void set_position(std::pair<int, int> pos) { position_ = pos; }
    Bearing get_bearing() const { return bearing_; };
    void turn_right();
    void turn_left();
    void advance();
    void execute_sequence(std::string seq);
private:
    std::pair<int, int> position_{0, 0};
    Bearing bearing_{Bearing::NORTH};
};

}  // namespace robot_simulator

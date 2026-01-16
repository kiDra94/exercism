#pragma once
#include <string>
#include <vector>
namespace speedywagon {
struct pillar_men_sensor {
    int activity{};
    std::string location{};
    std::vector<int> data{};
};
bool connection_check(pillar_men_sensor* ps);
int uv_light_heuristic(std::vector<int>* data_array);
int activity_counter(pillar_men_sensor* sensors, size_t dimension);
bool alarm_control(pillar_men_sensor* ps);
bool uv_alarm(pillar_men_sensor* ps);
}  // namespace speedywagon

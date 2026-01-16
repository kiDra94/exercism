#pragma once

#include <string>
#include <vector>

namespace speedywagon {

struct pillar_men_sensor {
    int activity{};
    std::string location{};
    std::vector<int> data{};
};

int uv_light_heuristic(std::vector<int>* data_array);

bool connection_check(pillar_men_sensor* pms);
int activity_counter(const pillar_men_sensor* sensors, size_t size);
bool alarm_control(pillar_men_sensor* pms);
bool uv_alarm(pillar_men_sensor* pms);

}  // namespace speedywagon

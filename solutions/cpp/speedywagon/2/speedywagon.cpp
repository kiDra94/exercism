#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

bool connection_check(pillar_men_sensor* pms){
    if(pms != nullptr){ return true;};
    return false;
}

int activity_counter(std::vector<int>* data, size_t size){
    int result{0};
    for(size_t i = 0; i < size; i++){
        result += (*data)[i];
    }
    return result;
}

bool alarm_control(pillar_men_sensor* pms){
    int activity = activity_counter(&pms->data, sizeof(pms->data));
    if(connection_check(pms) && (activity > 0)){
        return true;
    }
    return false;
}

bool uv_alarm(pillar_men_sensor* pms){
    int ulh = uv_light_heuristic(&pms->data);
    if(connection_check(pms) && (ulh > pms->activity)){
        return true;
    }
    return false;
}

}  // namespace speedywagon

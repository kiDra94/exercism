#include "difference_of_squares.h"
#include <cstdint>
namespace difference_of_squares {

// TODO: add your solution here
int32_t difference(int32_t number){
    return square_of_sum(number) - sum_of_squares(number);
}
int32_t square_of_sum(int32_t number){
    int32_t result{0};
    for(int32_t i = 1; i <= number; i++){
        result += i;
    }
    return result*result;
}
int32_t sum_of_squares(int32_t number){
    int32_t result{0};
    for(int32_t i = 1; i <= number; i++){
        result += i*i;
    }
    return result;
}

}  // namespace difference_of_squares

#include "eliuds_eggs.h"

namespace chicken_coop {

int positions_to_quantity(int egg_laying_spots)
{
    int helper{0};
    const int it = egg_laying_spots;
    for(int i = 0; i < it; i++){
        if(1 & egg_laying_spots){
            helper++;
        }
        egg_laying_spots >>=1;
    }
    return helper;
}

}  // namespace chicken_coop

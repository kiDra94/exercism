#include "doctor_data.h"

namespace heaven {
    Vessel Vessel::replicate ( std::string name ) const {
        return Vessel(name, 2);
    }
    bool Vessel::shoot_buster() {
        if(busters > 0){
            busters--;
            return true;
        }
        return false;
    };

    std::string get_older_bob ( Vessel a, Vessel b ) {
        if(a.generation < b.generation){
            return a.get_name();
        }
        return b.get_name();
    };

    bool in_the_same_system ( Vessel a, Vessel b ) {
        return a.current_system == b.current_system;
    }


}

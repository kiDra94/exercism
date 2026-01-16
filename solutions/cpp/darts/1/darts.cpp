#include "darts.h"
#include <cmath>

namespace darts {

int score(double x, double y)
{
    double distance_vektor = sqrt(pow(x, 2) + pow(y, 2));
    if(distance_vektor <= 1) return 10;
    else if(distance_vektor <= 5) return 5;
    else if(distance_vektor <= 10) return 1;
    return 0;
}


}  // namespace darts

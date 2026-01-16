#include "sieve.h"
#include <vector>
#include <unordered_set>

namespace sieve {

// TODO: add your solution here
    std::vector<int> primes ( int nbr ) {
        std::vector<int> prime_nbrs{};
        std::unordered_set<int> multiples{};
        if(nbr < 2) { return prime_nbrs;};

        for(int i = 2; i <= nbr; ++i) {
            if(multiples.find(i) == multiples.end()) {
                prime_nbrs.push_back(i);
            }
            int helper = i;
            while(helper < nbr){
                helper += i;
                multiples.insert(helper);
            }
        }

        return prime_nbrs;
    }


}  // namespace sieve

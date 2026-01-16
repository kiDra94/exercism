#include "allergies.h"
#include <string>
#include <unordered_set>


namespace allergies {

    void allergy_test::fill_results_ ( unsigned int value ) {
        for(int i = 0; i < 8; ++i){
            if((1 << i) & value){
                std::string allergen = allergens_[i];
                results_.insert(allergen);
            };
        };
    };

    bool allergy_test::is_allergic_to ( std::string allergie ) {
        return results_.contains(allergie);
    }



}  // namespace allergies

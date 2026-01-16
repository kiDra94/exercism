#pragma once
#include <string>
#include <unordered_set>
#include <vector>

namespace allergies {

class allergy_test {
public:
    allergy_test();
    allergy_test(unsigned int val) : value_{val} {
        fill_results_(val);
    }
    bool is_allergic_to(std::string allergie);
    std::unordered_set<std::string> get_allergies(){return results_;};
private:
    unsigned int value_{0};
    std::unordered_set<std::string> results_{};
    void fill_results_(unsigned int value);
    const std::vector<std::string> allergens_ = {
    "eggs",
    "peanuts",
    "shellfish",
    "strawberries",
    "tomatoes",
    "chocolate",
    "pollen",
    "cats"
};
};

}  // namespace allergies

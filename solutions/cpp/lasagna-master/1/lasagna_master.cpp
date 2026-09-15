#include "lasagna_master.h"
#include <algorithm>

namespace lasagna_master {

int preparationTime(std::vector<std::string> layers, int time) {
    return static_cast<int>(layers.size()) * time;
}

amount quantities(std::vector<std::string> layers) {
    amount result{0, 0.0};

    std::for_each(layers.begin(), layers.end(), [&result](const std::string& layer) {
        if (layer == "noodles") {
            result.noodles += 50;
        } else if (layer == "sauce") {
            result.sauce += 0.2;
        }
    });

    return result;
}

void addSecretIngredient(std::vector<std::string> &myList, std::vector<std::string> friendsList) {
	 myList.at(myList.size()-1) = friendsList.back();
}

std::vector<double> scaleRecipe(const std::vector<double> &quantities, int portions) {
	std::vector<double> result;
	for(const auto& q : quantities){
		result.push_back(q * portions/2);
	}

	return result;
}

void addSecretIngredient(std::vector<std::string> &myList,std::string auntiesSecret) {
	// myList.at(myList.size()-1) = auntiesSecret;
	myList.pop_back();
	myList.push_back(auntiesSecret);
}
}  // namespace lasagna_master

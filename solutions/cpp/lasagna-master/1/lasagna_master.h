#pragma once
#include <vector>
#include <string>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

int preparationTime(std::vector<std::string> layers, int time=2);

amount quantities(std::vector<std::string> layers);

void addSecretIngredient(std::vector<std::string>& myList, std::vector<std::string>friendsList);

void addSecretIngredient(std::vector<std::string>& myList, std::string auntiesSecret);

std::vector<double> scaleRecipe(const std::vector<double>& quantities, int portions);

}  // namespace lasagna_master

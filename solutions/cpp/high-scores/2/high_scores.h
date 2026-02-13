#pragma once

#include <vector>

namespace arcade {

class HighScores {
   private:
    std::vector<int> scores_;

   public:
    HighScores(std::vector<int> scores) : scores_(scores){};

    std::vector<int> list_scores() { return scores_;};

    int latest_score();

    int personal_best();

    std::vector<int> top_three();
};

}  // namespace arcade

#include "high_scores.h"
#include <vector>
#include <algorithm>

namespace arcade {

int HighScores::latest_score() {
    return scores_.back();
}

int HighScores::personal_best() {
    return *std::max_element(scores_.begin(), scores_.end());
}

std::vector<int> HighScores::top_three() {
    std::vector<int> helper = scores_;
    std::sort(helper.rbegin(), helper.rend());
    int count = std::min(3, static_cast<int>(helper.size()));
    return std::vector<int>(helper.begin(), helper.begin() + count);
}

}  // namespace arcade

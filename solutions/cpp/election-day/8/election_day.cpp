#include <string>
#include <vector>

namespace election {

// The election result struct is already created for you:

struct ElectionResult {
    // Name of the candidate
    std::string name{};
    // Number of votes the candidate has
    int votes{};
};

int vote_count(ElectionResult& er){
    return er.votes;
}

void increment_vote_count(ElectionResult& er, int nbr){
    er.votes += nbr;
}

ElectionResult& determine_result(std::vector<ElectionResult>& final_count){
    //ElectionResult& winner = final_count[0];
    int winner_index{0};
    int max{0};
    for(int i = 0; i < final_count.size(); i++){
        if(final_count[i].votes > max){
            max = final_count[i].votes;
            winner_index = i;
        }
    }
    final_count[winner_index].name = "President " + final_count[winner_index].name;
    return final_count[winner_index];
}

}  // namespace election

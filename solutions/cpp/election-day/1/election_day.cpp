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

ElectionResult determine_result(std::vector<ElectionResult>& final_count){
    ElectionResult& winner = final_count[0];
    for(const auto& cnt: final_count){
        if(cnt.votes > winner.votes){
            winner = cnt;
        }
    }
    winner.name = "President " + winner.name;
    return winner;
}

}  // namespace election

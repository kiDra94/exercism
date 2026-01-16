#include <array>
#include <string>
#include <vector>
#include <cmath>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> rounded_down{};
    for(double i: student_scores) rounded_down.push_back(static_cast<int>(i));
    return rounded_down;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int passed_students{0};
    for(int i: student_scores) if(i <= 40) passed_students++;
    return passed_students;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    int lower_bound{41};
    int range = highest_score - lower_bound;
    int intervall = std::ceil(range / 4);
    std::array<int, 4> points{};
    for(int i = 0; i < points.size(); i++){
        points.at(i) = intervall*(i) + (lower_bound);
    }
    return points;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    // TODO: Implement student_ranking
    return {};
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    // TODO: Implement perfect_score
    return "";
}

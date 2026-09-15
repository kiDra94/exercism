#include "alphametics.h"
#include <vector>
#include <set>
#include <cctype>
#include <algorithm>
#include <cmath>

namespace alphametics {

// Recursive backtracking algorithm
bool backtrack(size_t letter_idx, long long current_sum, int used_digits,
               std::map<char, int>& mapping,
               const std::vector<char>& unique_letters,
               const std::map<char, long long>& coefs,
               const std::set<char>& first_letters,
               const std::vector<long long>& suffix_max,
               const std::vector<long long>& suffix_min) {

    // Base case: All letters assigned
    if (letter_idx == unique_letters.size()) {
        return current_sum == 0;
    }

    // Early Pruning: If the sum cannot possibly reach 0 anymore, abort this branch
    if (current_sum + suffix_max[letter_idx] < 0) return false;
    if (current_sum + suffix_min[letter_idx] > 0) return false;

    char c = unique_letters[letter_idx];
    long long weight = coefs.at(c);
    bool is_first = first_letters.count(c) > 0;

    for (int d = 0; d <= 9; ++d) {
        // Leading zero solution is invalid
        if (d == 0 && is_first) continue;

        // Solution must have a unique value for each letter
        if (used_digits & (1 << d)) continue;

        mapping[c] = d;

        // Recurse with the updated sum and used digits bitmask
        if (backtrack(letter_idx + 1, current_sum + weight * d,
                      used_digits | (1 << d),
                      mapping, unique_letters, coefs, first_letters,
                      suffix_max, suffix_min)) {
            return true;
        }
    }
    return false;
}

std::optional<std::map<char, int>> solve(const std::string& puzzle) {
    std::vector<std::string> words;
    std::string current_word = "";

    for (char c : puzzle) {
        if (std::isalpha(c)) {
            current_word += c;
        } else {
            if (!current_word.empty()) {
                words.push_back(current_word);
                current_word = "";
            }
        }
    }
    if (!current_word.empty()) {
        words.push_back(current_word);
    }

    if (words.size() < 2) return std::nullopt;

    std::map<char, long long> coefs;
    std::set<char> first_letters;

    for (size_t i = 0; i < words.size(); ++i) {
        const std::string& w = words[i];
        first_letters.insert(w[0]);

        long long weight = 1;
        for (int j = static_cast<int>(w.length()) - 1; j >= 0; --j) {
            if (i == words.size() - 1) {
                coefs[w[j]] -= weight;
            } else {
                coefs[w[j]] += weight;
            }
            weight *= 10;
        }
    }

    std::vector<char> unique_letters;
    for (const auto& [k, v] : coefs) {
        unique_letters.push_back(k);
    }

    if (unique_letters.size() > 10) return std::nullopt;

    std::sort(unique_letters.begin(), unique_letters.end(), [&coefs](char a, char b) {
        return std::abs(coefs[a]) > std::abs(coefs[b]);
    });

    std::vector<long long> suffix_max(unique_letters.size(), 0);
    std::vector<long long> suffix_min(unique_letters.size(), 0);
    for (int i = static_cast<int>(unique_letters.size()) - 1; i >= 0; --i) {
        long long c = coefs[unique_letters[i]];
        long long next_max = (i + 1 < static_cast<int>(unique_letters.size())) ? suffix_max[i + 1] : 0;
        long long next_min = (i + 1 < static_cast<int>(unique_letters.size())) ? suffix_min[i + 1] : 0;

        suffix_max[i] = next_max + (c > 0 ? c * 9 : 0);
        suffix_min[i] = next_min + (c < 0 ? c * 9 : 0);
    }

    std::map<char, int> mapping;
    if (backtrack(0, 0, 0, mapping, unique_letters, coefs, first_letters, suffix_max, suffix_min)) {
        return mapping;
    }

    return std::nullopt;
}

}  // namespace alphametics

#if !defined(ALPHAMETICS_H)
#define ALPHAMETICS_H

#include <string>
#include <map>
#include <optional>

namespace alphametics {

    std::optional<std::map<char, int>> solve(const std::string& puzzle);

}  // namespace alphametics

#endif  // ALPHAMETICS_H

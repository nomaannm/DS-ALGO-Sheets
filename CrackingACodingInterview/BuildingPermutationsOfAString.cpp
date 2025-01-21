#include <iostream>
#include <string>
#include <vector>
#include <set>

auto buildingPermutationsOfAString(const std::string& str) -> std::set<std::string> {
    std::set<std::string> permutations;

    if (str.size() == 1) {
        permutations.insert(str);
        return permutations;
    }

    for (size_t i = 0; i < str.size(); i++) {
        std::string remaining = str.substr(0,i) + str.substr(i+1);
        auto subPerms = buildingPermutationsOfAString(remaining);

        for (const auto& subperm : subPerms) {
            permutations.insert(str[i] + subperm);
        }
    }

    return permutations;
}


int main() {
    std::string str = "abc";
    auto answers = buildingPermutationsOfAString("abc");
    for (const auto& answer : answers) {
        std::cout << answer << std::endl;
    }

    return 0;
}

#include <iostream>
#include <chrono>
#include <vector>

int findingCommonElements(std::vector<int>& v1, std::vector<int>& v2) {
    int count = 0;
    for (const auto &i : v1) {
        for (const auto &j : v2) {
            if (i == j) {
                count++;
            }
        }
    }

    return count;
}

int main() {

    std::vector<int> v1;
    for (int i = 1; i <= 100; i++) {
        v1.push_back(i);
    }

    std::vector<int> v2;
    for (int i = 0; i <= 100; i += 2) {
        v2.push_back(i);
    }


    auto start = std::chrono::high_resolution_clock::now();
    auto ans = findingCommonElements(v1, v2);

    auto end = std::chrono::high_resolution_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time elapsed : " <<  elapsed.count() << " microseconds" << std::endl;
    std::cout << "Answer : " << ans << std::endl;
    return 0;
}

#include <cstdint>
#include<iostream>
#include <vector>
using namespace std;

int countPrimes(int n) {
    if (n < 2) return 0;

    int size = (n + 31)/32;
    vector<uint32_t> isComposite(size, 0);

    int count = 0;
    for (int i = 2; i < n; i++) {
        int index = i/32;
        int bit = i % 32;
        if (!(isComposite[index] & (1U << bit))) {
            count++;

            for (int j = i*i; j < n; j += i) {
                isComposite[j/32] |= (1U << (j % 32));
            }

        }
    }
    return count;
}

int main() {
    cout << countPrimes(3) << endl;
}

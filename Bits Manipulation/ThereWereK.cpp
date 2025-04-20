/*
 * Given an integer n , find the maximum value of integer k such that the following condition holds:
 * n & (n−1) & (n−2) & (n−3) & ... (k) = 0 where & denotes the bitwise AND operation.
 */

#include <iostream>
using namespace std;

int findK(int n) {
    int res = n;
    for (int k= n-1; k >= 0; k--) {
        res &= k;
        if (res == 0) return k;
    }
    return 0;
}

int main() {
    cout << findK(100) << endl;
}

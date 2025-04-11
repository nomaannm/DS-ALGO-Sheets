#include <iostream>
#include <algorithm>
using namespace std;

long long GCD(long long a, long long b) {
    return b == 0 ? a : GCD(b, a % b);
}

long long LCM(long long a, long long b) {
    return a * b / GCD(a, b);
}

int nthUglyNumber(int n, int a, int b, int c) {
    long long low = 1, high = 2E9;
    long long ans = -1;
    long long ab = LCM(a, b);
    long long ac = LCM(a ,c);
    long long bc = LCM(b ,c);
    long long abc = LCM(LCM(a,b),c);

    while (low <= high) {
        long long mid = low + (high-low)/ 2;
        long long count = mid/a + mid/b + mid/c - mid/ab - mid/ac - mid/bc + mid/abc;

        if (count < n) {
            low = mid + 1;
        } else {
            high = mid - 1;
            ans = mid;
        }

    }

    return (int)ans;

}

int main() {
    cout << nthUglyNumber(3, 2, 3, 5)  << endl;
}

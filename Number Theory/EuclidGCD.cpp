#include <iostream>
#include <map>
using namespace std;

int euclid_gcd(int a, int b, map<pair<int, int>, int>& memo) {
    pair<int, int> key = {min(a, b), max(a,b)};
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }
    if (b == 0) {
        memo[key] = a;
        return a;
    }
    if (a == 0) {
        memo[key] = b;
        return b;
    }
    memo[key] = euclid_gcd(b, a%b, memo);
    return memo[key];
}

int main() {
    map<pair<int, int>, int> memo;
    cout << euclid_gcd(3, 5, memo) << endl;
    cout << euclid_gcd(10, 7, memo) << endl;

    cout << euclid_gcd(100, 9927, memo) << endl;
    cout << euclid_gcd(99, 992727891838287328, memo) << endl;
}

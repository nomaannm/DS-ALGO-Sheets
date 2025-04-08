#include <cstdint>
#include <iostream>
#include <map>
#include <chrono>
using namespace std;

int
MEMOIZEDFibonacci(int n, map<int, int>& memo) {
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }
    if (n == 0 || n == 1) {
        memo[n] = n;
        return n;
    }
    memo[n] = MEMOIZEDFibonacci(n-1, memo) + MEMOIZEDFibonacci(n-2, memo);
    return memo[n];
}

int BASICFibonacci(int n) {
    if (n == 0 || n == 1) { return n; }
    return BASICFibonacci(n-1) + BASICFibonacci(n-2);
}

int main() {
    map<int,int> memo;
    cout << "MEMOIZATION\n";
    auto MEMOIZEDstart = chrono::high_resolution_clock::now();
    for (uint8_t i=0; i < 100; i++) {
        cout << MEMOIZEDFibonacci(i, memo) << ", ";
    }
    auto MEMOIZEDend = chrono::high_resolution_clock::now();
    auto MEMOIZEDduration = chrono::duration_cast<chrono::microseconds>(MEMOIZEDend - MEMOIZEDstart);
    cout << MEMOIZEDduration.count() << " microseconds\n";

    auto BASICstart = chrono::high_resolution_clock::now();
    cout << "\nBASIC\n";
    for (uint8_t i=0; i < 100; i++) {
        cout << BASICFibonacci(i) << ", ";
    }
    auto BASICend = chrono::high_resolution_clock::now();
    auto BASICduration = chrono::duration_cast<chrono::microseconds>(BASICend - BASICend);
    cout << BASICduration.count() << " microseconds\n";
}

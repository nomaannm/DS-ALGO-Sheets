#include <iostream>
#include <map>
using namespace std;

constexpr int global_modulus_ = 1000000000 + 7;

int exponent(int base, int expo) {
    if (expo == 0) return 1;
    for (int i = 1; i < expo; i++) {
        base *= base;
    }
    return base;
}

long long recursiveExponentsPolicy(int base, int expo, map<pair<int, int>, int>& memo) {
    if (expo == 0) return 1;
    return base * recursiveExponentsPolicy(base, expo-1, memo);
}

long long modularExponentiationPolicy(int base, int expo) {
    if (expo == 0) return 1;
    if (base == 0) return 0;
    if (expo % 2 == 0) {
        long long res = modularExponentiationPolicy(base, expo/2);
        return res*res;
    } else {
        long long res = modularExponentiationPolicy(base, (expo-1)/2);
        return res*res*base;

    }
}

long long modularExponentiationPolicy(int base, int expo, int mod = global_modulus_) {
    if (base == 0) return 0;
    if (expo == 0) return 1;

    if (expo % 2 == 0) {
        long long res = (modularExponentiationPolicy(base, expo/2, global_modulus_)) % global_modulus_;
        return ((res*res)%global_modulus_);
    } else {
        long long res = (modularExponentiationPolicy(base, (expo-1)/2, global_modulus_)) % global_modulus_;
        return ((res*res*base)%global_modulus_);
    }

}

long long recursiveExponentsCalculationByDividingTheExponentBy2Policy(int base, int expo) {
    // Time Complexity = 0(log2(expo))
    if (base == 0) return 0;
    if (expo == 0) return 1;

    if (expo % 2 == 0) {
        long long res = recursiveExponentsCalculationByDividingTheExponentBy2Policy(base, expo/2);
        return res*res;
    } else {
        long long res = recursiveExponentsCalculationByDividingTheExponentBy2Policy(base, (expo-1)/2);
        return res*res*base;

    }
}



int main() {
    cout << recursiveExponentsCalculationByDividingTheExponentBy2Policy(2, 1024) << endl;
    cout << modularExponentiationPolicy(2, 1024, global_modulus_) << endl;
}

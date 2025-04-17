#include <iostream>
#include <vector>
using namespace std;

int GCD(int a, int b) {
    if (b == 0) return a;
    if (a == 0) return b;
    return GCD(b, a%b);
}

long long modularExponentiationPolicy(int base, int expo, int mod) {
    if (base == 0) return 0;
    if (expo == 0) return 1;

    if (expo % 2 == 0) {
        long long res = (modularExponentiationPolicy(base, expo/2, mod)) % mod;
        return ((res*res)%mod);
    } else {
        long long res = (modularExponentiationPolicy(base, (expo-1)/2, mod)) % mod;
        return ((res*res*base)%mod);
    }

}

bool arePairWiseCoPrime(vector<int>& mods) {
    int n = mods.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (GCD(mods[i], mods[j]) != 1) {
                return false;
            }
        }
    }
    return true;
}

long long modularInverse(long long a, long long m) {
    // GCD(a,m) != 1, Inverse doesn't exists
    if (GCD(a, m) != 1) {
        return -1;
    }
    // Modular Inverse of a % m = modular exponentiation (a, m-2)%m;
    int modularInverse = modularExponentiationPolicy(a, (m-2), m);
    return modularInverse;

}

void chineseRemainderTheorem(vector<int>& remainders, vector<int>& mods, long long& x) {
    if (arePairWiseCoPrime(mods)) {
        long M = 1;
        for (int m : mods) {
            M *= m;
        }

        x = 0;
        for (int i = 0; i < mods.size(); i++) {
            long mI = M/mods[i];
            long long mI_inverse = modularInverse(mI, mods[i]);
            x = (x + (mI_inverse*mI*remainders[i] ) )%M;
        }

        if ( x < 0) x += M;


    } else {
        cout << "Can't apply chinese remainder theorem to this!";
    }
}

int main() {
    //Test Case 1
    long long x;
    vector<int> mods = {5, 7, 8};
    vector<int> remainders = {1, 2, 3};
    chineseRemainderTheorem(remainders, mods, x);
    cout << x << endl;

    cout << modularInverse(35, 8) << endl;

}

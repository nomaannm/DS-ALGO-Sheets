#include <iostream>

using namespace std;

/*
 *@fermats_theorem
 *if(GCD(a,p) == 1)
 *a^(p-1) % p will always be 1
 */


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

void modularInverse(int a, int m) {
    // GCD(a,m) != 1, Inverse doesn't exists
    if (GCD(a, m) != 1) {
        cout << "Modular inverse does not exist" << endl;
    }
    // Modular Inverse of a % m = modular exponentiation (a, m-2)%m;
    int modularInverse = modularExponentiationPolicy(a, (m-2), m);
    cout << modularInverse << endl;

}

int main() {
    modularInverse(3, 7);
}

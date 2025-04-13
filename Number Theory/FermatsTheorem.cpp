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

long long modularInverse(long long a, long long m) {
    // GCD(a,m) != 1, Inverse doesn't exists
    if (GCD(a, m) != 1) {
        return -1;
    }
    // Modular Inverse of a % m = modular exponentiation (a, m-2)%m;
    int modularInverse = modularExponentiationPolicy(a, (m-2), m);
    return modularInverse;

}

//We have to compute nCr % p
// nCr = n!/r!*(n-r)!

int nChoosingR(int n, int r) {
    if (n == 0 ) return 0;
    if (r == 0 || r == n) return 1;
    if (r == 1) return n;

    return nChoosingR(n-1, r-1) + nChoosingR(n-1, r);
}



// But using fermat little
int fermatLittleChoosingPolicy(int n, int r, int m) {
    if (r < 0 || r > n || n==0) return 0;
    if (r== 0 || r == n) return 1;
    if (r == 1) return n;

    long long numerator = 1LL;
    long long denominator = 1LL;
    for (int i=0; i < r; i++) {
        numerator = (numerator * (n - i)) % m;
        denominator = (denominator * (i + 1)) % m;
    }

    return int(numerator * modularInverse(denominator, m)) % m;


}






int main() {
    cout << nChoosingR(10, 2) << endl;
    cout << fermatLittleChoosingPolicy(10, 2, 1000000007) << endl;
}

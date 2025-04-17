#include <complex>
#include <iostream>
#include <math.h>
using namespace std;


bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }

    return true;

}

void almostPrime(int n, int k) {
    if (isPrime(n)) {
        cout << n << " is a prime number, and can't be evaluated for this identity!\n";
        return;
    }
    // Almost Prime if n has exactly two prime factors;
    int count = 0;
    for (int i = 2; i*i <= n; i++) {
        if (count == k) break;
        if (n % i == 0 && isPrime(i)) {
            count++;
            if (isPrime(n/i) && i != n/i) count++;
        }
    }
    if (count == k) {
        cout << n << " is an almost prime, as it has exactly " << k << " prime factors!\n";
    } else {
        cout << n << " is not an almost prime, as it does not have exactly " << k << " prime factors!\n";
    }

}

int main() {
    for (int i = 1; i <= 20; i++) {
        almostPrime(i, 2);
    }
}

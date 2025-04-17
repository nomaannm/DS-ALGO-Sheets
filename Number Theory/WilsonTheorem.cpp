#include<iostream>
using namespace std;

bool wilsonTheorem(int number) {
    if (number < 2) return false;
    long long fact = 1;
    for (int i = 1; i < number; i++) {
        fact = fact * i;
    }
    return (fact % number) == (number - 1);
}

int main() {
    for (int i = 1; i <= 20; i++) {
        cout << i << ": " << wilsonTheorem(i) << endl;
    }
}

#include<iostream>

int
extendedEuclidAlgorithm(int a, int b, int&x, int& y) {
    // a*x + b*y = GCD(a,b)
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int d = extendedEuclidAlgorithm(a, a%b, x1, y1);
    x = y1;
    y = x1-y1 * (a/b);
    return d;
}

int main() {
    int x, y;
    int a = 30, b = 12;

    int d = extendedEuclidAlgorithm(a, b, x, y);


}

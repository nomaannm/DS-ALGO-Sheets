#include <iostream>
#include <vector>
using namespace std;


int eulerTotient(int n) {
    if (n == 1) return 1;
    int result = n;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

vector<int> eulerTotientSumToN(int n) {
    vector<int> result;
    int sum = 0;
    for(int i=1; i*i <= n; i++) {
        if(n % i == 0) {
            sum += eulerTotient(i);
            result.push_back(i);
            if(i != n/i) { 
                sum += eulerTotient(n/i);
                result.push_back(n/i);
            }
        }
    }

    return result;
}






int main() {
    cout << eulerTotient(8) << endl;
    auto eulerTotientOf10 = eulerTotientSummationToN(10);
    for (auto i : eulerTotientOf10) {
        cout << i << " ";
    }


    eulerTotientOf10.clear();
    eulerTotientOf10 = eulerTotientSumToN(10);
    for (auto i : eulerTotientOf10) {
        cout << i << " ";
    }

}

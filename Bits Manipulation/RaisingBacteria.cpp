/*
 *Raising Bacteria problem on CodeForces
 */
#include<iostream>
using namespace std;

int minimumBacteriaToAdd(int x) {
    int count = 0;
    while (x) {
        x &= (x - 1);
        count++;
    }

    return count;

}

int main() {
    cout<<minimumBacteriaToAdd(100)<<endl;
}

#include <algorithm>
#include<iostream>
#include<vector>
#include <bits/ranges_algo.h>
using namespace std;

//merging the two sorted halves
void merge(vector<int>& vec, int left, int mid, int right) {
    int n1 = mid - left + 1; //Size of the left subarray
    int n2 = right - mid; //Size of the right subarray

    vector<int> L(n1, 0);
    vector<int> R(n2, 0);

    for(int i = 0; i < n1; i++) {
        L[i] = vec[left+i];
    }

    for(int i = 0; i < n2; i++) {
        R[i] = vec[mid+1+i];
    }

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    //Remaining L[] elements into vec
    while (i < n1) {
        vec[k] = L[i];
        i++;
    }

    //Remaining R[] elements into vec
    while (j < n2) {
        vec[k] = R[j];
        j++;
    }

    return;



}

void mergeSort(vector<int>& unsorted, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(unsorted, left, mid);
    mergeSort(unsorted, mid + 1, right);

    merge(unsorted, left, mid, right);
}

int main() {
    vector<int> unsorted = { 10, 1, 2, 3, 7, 8, 4, 6, 5, 9};
    mergeSort(unsorted, 0, unsorted.size() - 1);
    for (auto i : unsorted) {
        cout << i << " ";
    }
}

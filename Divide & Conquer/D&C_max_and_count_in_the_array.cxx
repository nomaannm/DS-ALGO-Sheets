/*
 *@brief
 *Divide & Conquer
 *The problem is to be divided and then individual divisions have to be solved!
 *It is a recursive algorithm!
 *Example : Quicksort, etc
 *
 */

#include<iostream>
#include<vector>
using namespace std;

// D&C for summing up an array using recursion
int divide_and_conquer_for_array_sum(vector<int> arr, int index = 0) {
    if (index == arr.size()) return 0;
    return arr[index] + divide_and_conquer_for_array_sum( arr, index+1);
}

int d_and_c_counting(vector<int> arr, int index = 0) {
    if (index == arr.size()) return 0;
    return 1 + d_and_c_counting(arr, index+1);
}

int d_and_c_max_in_list(vector<int> arr, int index = 0) {
    if (index == arr.size()-1) return arr[index];
    return max(arr[index], d_and_c_max_in_list(arr, index+1));
}

int main() {
    vector<int> arr;
    for (int i=1; i < 100; i++) arr.emplace_back(i);


    cout << divide_and_conquer_for_array_sum(arr) << endl;
    cout << d_and_c_counting(arr) << endl;

    vector<int> arr2 = {1,2,4};
    cout << d_and_c_max_in_list(arr2);
}

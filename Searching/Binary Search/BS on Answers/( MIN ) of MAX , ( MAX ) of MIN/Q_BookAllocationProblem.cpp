#include<bits/stdc++.h>
int findMax(vector<int>& arr){
    int maxi = INT_MIN;
    for(auto x : arr){
        maxi = max(maxi,x);
    }
    return maxi;
}

int summation(vector<int>& arr){
    int sum = 0;
    for(auto x : arr){
        sum += x;
    }
    return sum;
}

int cntStudents(vector<int>& arr, int& pages){
    int student = 1, pagesStudent = 0;
    for(auto x : arr){
        if(pagesStudent + x <= pages){
            pagesStudent += x;
        }
        else{
            student++;
            pagesStudent = x;
        }
    }
    return student;

    
}

int findPages(vector<int>& arr, int n, int m) {
    if(n < m) return -1;
    int low = findMax(arr);
    int high = summation(arr);
    while (low <= high) {
      int mid = (low + high) / 2;
      if (cntStudents(arr, mid) > m)
        low = mid + 1;
      else
        high = mid - 1;
    }
    return low;
}




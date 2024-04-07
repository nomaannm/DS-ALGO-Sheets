// coding ninjas - merge 2 sorted arrays, find their union
#include<iostream>
#include<vector>
vector < int > sortedArray(vector < int > a, vector < int > b) {
    int i = 0;
    int j = 0;

    vector<int> unionarr;

    while(i < a.size() && j < b.size()){
        if(a[i] <= b[j]){
            if(unionarr.size() == 0 || unionarr.back() != a[i]) unionarr.push_back(a[i]);
            i++;

        }
        else if(a[i] > b[j]){
            if(unionarr.size() == 0 || unionarr.back() != b[j]) unionarr.push_back(b[j]);
            j++;
        }

    }

    while(i < a.size()){
        if(unionarr.size() == 0 || unionarr.back() != a[i])
        unionarr.push_back(a[i]);
        i++;
    }

    while(j < b.size()){
        if(unionarr.size() == 0 || unionarr.back() != b[j])
        unionarr.push_back(b[j]);
        j++;
    }


    return unionarr;
}

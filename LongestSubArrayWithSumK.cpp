#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    map<int,int> mpp;
    int sum = 0 ; 
    int maxLen = 0 ;
    for(int i = 0 ; i < nums.size() ; i++){
        sum += nums[i];
        if(sum == k ){
            maxLen = max(maxLen , i+1);
        }

        int rem = sum - k;
        if(mpp.find(rem) != mpp.end()){
            int len = i - mpp[rem];
            maxLen = max(maxLen , len);
            
        }
        if(mpp.find(sum) == mpp.end()) {mpp[sum] = i;}
    }

    return maxLen;
}

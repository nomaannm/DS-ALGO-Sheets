class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = INT_MIN, high = 0;
        for(auto x : weights){
            if(low < x) low = x;
            high += x;
        }
        int ans  = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(isPossible(weights,mid,days)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }
        return ans;
        
    }

    bool isPossible(vector<int>& W, int capacity, int& days){
        int currentWeight = 0;
        int requiredDays = 1;
        for(int weight : W){
            if(currentWeight + weight > capacity){
                requiredDays++;
                currentWeight = weight;
            }
            else {
                currentWeight += weight;
            }
        }

        return requiredDays <= days;
    }

};

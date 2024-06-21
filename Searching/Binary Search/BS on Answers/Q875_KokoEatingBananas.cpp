class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1 , high = findMax(piles);
        while(low <= high){
            int mid = (low + high)/2;
            auto totalH = calculateTotalHours(piles,mid);
            if(totalH <= h){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return low;
        
    }

    long long calculateTotalHours(vector<int>& piles , int hourly){
        long long totalH = 0;
        int n = piles.size();
        for(auto x : piles){
            totalH += ceil(double(x)/double(hourly));
        }
        return totalH;
    }

    int findMax(vector<int>& nums){
        int maxElement = INT_MIN;
        for(auto x : nums) maxElement = max(maxElement,x);
        return maxElement;
    }
};

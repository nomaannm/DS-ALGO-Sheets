// Similar to Koko Eating Bananas
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = findMax(nums);
        while(low <= high){
            int mid = (low + high)/2;
            if(divideAndSum(nums,mid) <= threshold){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return low;
        
    }
    int findMax(vector<int>& nums){
        int MAX = INT_MIN;
        for(auto x : nums){
            if(x > MAX) MAX = x;
        }
        return MAX;
    }

    int divideAndSum(vector<int>& nums, int divisor){
        int sum = 0 ;
        for(auto x : nums){
            sum += ceil(double(x) / double(divisor));
        }
        return sum;
    }
};

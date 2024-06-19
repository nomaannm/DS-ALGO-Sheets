class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(LB(nums,target) == nums.size() || nums[LB(nums,target)] != target) return {-1,-1};

        return {LB(nums,target) , UB(nums,target) - 1};
        
    }

    int LB(vector<int>& nums , int& target){
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();

        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] >= target){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    int UB(vector<int>& nums , int& target){
        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();

        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] > target){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};

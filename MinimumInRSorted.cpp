//LEETCODE 153
class Solution {
public:
    int findMin(vector<int>& nums) {
        int minElem = INT_MAX;
        int low = 0 , high = nums.size() - 1;
        if(nums[low] <= nums[high] ) return nums[low];
        while(low <= high){
            int mid = (low + high)/2;
            minElem = min(minElem, nums[mid]);
            if(nums[low] <= nums[mid]){
                minElem = min(minElem,nums[low]);
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return minElem;
        
    }
};

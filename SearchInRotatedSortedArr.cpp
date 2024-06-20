// LEETCODE 33
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0 , high = nums.size() - 1;
        
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target) return mid;
            else{
                if(nums[low] <= nums[mid]){
                    //L E F T   S O R T E D
                    if(nums[low] <= target && target <= nums[mid]) high = mid-1;
                    else low = mid + 1;
                    
                }else{
                    //R I G H T   S O R T E D
                    if(nums[mid] <= target && target <= nums[high]) 
                    low = mid + 1;
                    else high = mid - 1;
                    
                }
            }
        }
        
        return -1;
        
    }
};

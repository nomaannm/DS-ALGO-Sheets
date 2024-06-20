// LEETCODE 162
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return bs(nums);


    }

    int bs(vector<int>& nums){
        int mid = 0;
        int n = nums.size() ;
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;
        int low = 1;
        int high = n-2;
        while(low <= high){
            mid = (low + high)/2;
            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid + 1]){
                break;
            }
            else if(nums[mid-1] < nums[mid]){
                low = mid+1;
            }
            else if(nums[mid-1] > nums[mid]){
                high = mid-1;

            }
            else{
                low = mid + 1;
            }
        }
        return mid;
    }
};

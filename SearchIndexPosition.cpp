/**
Problem No . 35
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0 ;
        int end = nums.size();
        int mid ;
        if(target > nums[end-1]) return end ;
        while ( start <= end )
        {
            mid = start + (end-start)/2 ;
            if(nums[mid] == target) return mid ;
            else if (target < nums[mid]) end = mid - 1 ;
            else start = mid + 1;
        }
        return start ;


    }
};

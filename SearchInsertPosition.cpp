class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() -  1;

        int position = nums.size();

        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] >= target){
                high = mid - 1;
                position = mid;
            }
            else{
                low = mid + 1;
            }
        }

        return position;
    }
};

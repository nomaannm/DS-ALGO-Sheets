/**
* Problem 27
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int nonTargetElementIndex = 0 ;
        for(int i {0} ; i < nums.size() ; i++)
        {
            if(nums[i] != val){ nums[nonTargetElementIndex] = nums[i];
            nonTargetElementIndex ++ ; }
        }
        return nonTargetElementIndex ;
    }
};

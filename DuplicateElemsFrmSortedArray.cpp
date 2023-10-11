/**
* Problem 26
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int nonDuplicateElement = 1 ;
        for(int i{1} ; i < nums.size(); i++)
        {
            if(nums[i] != nums[i-1])
            {
                nums[nonDuplicateElement] = nums[i];
                nonDuplicateElement ++ ;
            }
        }
        return nonDuplicateElement ;
    }
};

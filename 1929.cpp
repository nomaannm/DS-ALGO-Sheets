class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> result;
        int n = nums.size() ;
        for(int i{0} ;i < 2*n ; i++)
        {
            result.push_back(nums[i % n]);
        }

        return result ;
    }
};

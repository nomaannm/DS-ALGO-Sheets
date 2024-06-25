class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int nOfSubsets = 1 << nums.size();
        int sum = 0;
        for(int num = 0; num < nOfSubsets; num++){
            int XOR = 0;
            for(int i = 0; i < nums.size(); i++){
                if(num & (1 << i)) XOR ^= nums[i];
            }
            sum += XOR;
        }
        return sum;
    }
};

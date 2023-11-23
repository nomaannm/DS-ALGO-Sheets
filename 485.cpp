class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0 ;
        int max = 0 ;
        for(auto x : nums){
            if( x != 1) count = 0 ;
            if(x == 1){
                count++;
                if(max < count) max = count ;
            }
        }

        return max ;
    }
};

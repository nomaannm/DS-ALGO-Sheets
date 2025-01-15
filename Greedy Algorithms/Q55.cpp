class Solution {
public:
    bool canJump(vector<int>& nums) {
       int maxDestination = 0;
       for(auto i=0; i < nums.size(); i++){
        if(i > maxDestination ) return false;
        maxDestination = max(maxDestination, i + nums[i]);
       }

       return true;

    }



};

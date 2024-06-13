#define COUNT int
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        COUNT count = 0 ;
        int elem;
        for(int i = 0 ; i < nums.size() ; i++){
            if(count  == 0){
                count = 1;
                elem = nums[i];
            }
            else if(nums[i] == elem){
                count++;
            }
            else{
                count--;
            }
        }
        int cnt1 = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == elem) cnt1++;
        }

        if(cnt1 > nums.size() / 2) return elem;
        return -1;
        
    }
};

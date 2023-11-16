//Problem : 189
class Solution {
public:
    void reverse(vector<int>& vec , int index , int index1){
        while(index < index1){
            swap(vec[index],vec[index1]);
            index++;
            index1--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        if(nums.size() < k ) k %= nums.size() ;

        reverse(nums,0,nums.size() - k - 1);
        reverse(nums,nums.size()-k,nums.size()-1);
        reverse(nums,0,nums.size()-1);

        
    }
};

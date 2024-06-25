class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(checkBits(i,k)) sum += nums[i];
        }
        return sum;
    }

    bool checkBits(int number , int& target){
        if(number == 0 || number == 1){
            if(target == number) return true;
        };
        int cnt = 0;
        while(number != 0){
            number = number & (number - 1);
            cnt += 1;
        }

        if(cnt == target) return true;
        return false;

    }
};

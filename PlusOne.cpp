Question : https://leetcode.com/problems/plus-one/description/?envType=study-plan-v2&envId=top-interview-150

Solution:
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int iterator = digits.size();
        for(int i{iterator - 1} ; i >=0 ; i--)
        {
            if(i == iterator - 1) digits[i]++;
            while(digits[i] > 9)
            {
                digits[i] = 0;
                if(i != 0) digits[i-1] = digits[i-1] + 1;
                else{
                    digits.push_back(0);
                    digits[i] = 1;
                }
            }
        }

        return digits;
    }
};

#define EACH(nums) for (const auto& x : nums)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int el1, el2;
        el1 = el2 = INT_MIN;
        EACH(nums) {
            if (cnt1 == 0 && x != el2) {
                cnt1 = 1;
                el1 = x;
            } else if (cnt2 == 0 && x != el1) {
                cnt2 = 1;
                el2 = x;
            } else if (el1 == x) {
                cnt1++;
            } else if (el2 == x) {
                cnt2++;
            } else {
                cnt1--, cnt2--;
            }
        }

        vector<int> ans;
        cnt1 = cnt2 = 0;

        int min = nums.size()/3 + 1;

        EACH(nums){
            if(x == el1) cnt1++;
            if(x == el2) cnt2++;
        }

        if(cnt1 >= min) ans.push_back(el1);
        if(cnt2 >= min) ans.push_back(el2);

        return ans;


    }
};

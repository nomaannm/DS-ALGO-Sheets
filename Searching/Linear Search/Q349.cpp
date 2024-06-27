class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        if(nums1.size() > nums2.size()){
            for(auto x : nums1){
                if(isPresent(nums2,x)) st.insert(x);
            }
        }else{
            for(auto x: nums2){
                if(isPresent(nums1,x)) st.insert(x);
            }
        }
        vector<int> ans(st.begin(), st.end()); 
        return ans;
    }

    bool isPresent(vector<int>& nums, int n){
        for(auto x : nums){
            if(x == n) return true;
        }
        return false;
    }
};

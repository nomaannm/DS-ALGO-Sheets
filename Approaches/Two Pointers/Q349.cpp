class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        int i = 0, j = 0;
        vector<int> ans;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] == nums2[j]){
                if(count(ans.begin(), ans.end(), nums1[i]) <= 0){
                    ans.push_back(nums1[i]);
                }
                i++;
                j++;
            }
            else if(nums1[i] > nums2[j]) j++;
            else i++;
        }
        return ans;    
    }

};

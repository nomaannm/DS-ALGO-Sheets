class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        vector<int> lastIndex(128, 0);

        for(int start = 0, end = 0; end < n; end++){
            char currentChar = s[end];
            start = max(start, lastIndex[currentChar]);
            maxLength = max(maxLength, end-start+1);
            lastIndex[currentChar] = end+1;

        }

        return maxLength;
    }
};

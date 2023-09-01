class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char ,int> romanMap;
        romanMap['I'] = 1;
        romanMap['X'] = 10;
        romanMap['V'] = 5;
        romanMap['L'] = 50;
        romanMap['C'] = 100;
        romanMap['M'] = 1000;
        romanMap['D'] = 500;
        int ans = 0 ;
        for(int i{0} ; i <= s.length() ; i++)
        {
            if(romanMap[s[i]] < romanMap[s[i+1]])
            {
                ans -= romanMap[s[i]];
            }
            else
            {
                ans += romanMap[s[i]];
            }
        }

        return ans;

        
    }
};

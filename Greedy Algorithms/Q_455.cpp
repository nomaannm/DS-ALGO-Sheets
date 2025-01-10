class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cookie = 0;
        int greed = 0;
        while(cookie < m && greed < n){
            if(g[greed] <= s[cookie]){
                greed += 1;
            }
            cookie += 1;
        }

        return greed;


    }
};

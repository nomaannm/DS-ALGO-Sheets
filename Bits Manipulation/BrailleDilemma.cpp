#include<iostream>
#include<string>
#include<vector>
#include<functional>
using namespace std;


int minTouches(vector<string>& arr) {
    int n = arr.size();
    int len = arr[0].size();
    vector<vector<int>> dp(len + 1, vector<int>(1 << n, -1));

    function<int(int, int)> solve = [&](int pos, int mask) -> int {
        if ((mask & (mask - 1)) == 0) return 0;  // only one or zero string in mask → unique
        if (pos == len) return 1e9;  // no positions left, but multiple strings remain
        if (dp[pos][mask] != -1) return dp[pos][mask];

        // Option 1: Skip this position
        int ans = solve(pos + 1, mask);

        // Option 2: Use this position
        int touches = 0;
        int zeroMask = 0, oneMask = 0;

        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) { // if string i is in the current group
                touches++; // we will touch this string at current position
                if (arr[i][pos] == '0') zeroMask |= (1 << i);
                else oneMask |= (1 << i);
            }
        }

        // Partition and recurse
        int total = solve(pos + 1, zeroMask) + solve(pos + 1, oneMask) + touches;
        ans = min(ans, total);

        return dp[pos][mask] = ans;
    };

    return solve(0, (1 << n) - 1);  // Start from position 0, with all strings included
}


int main() {
  vector<string> arr = {"101", "100", "000"};
  cout << minTouches(arr) << endl;
}



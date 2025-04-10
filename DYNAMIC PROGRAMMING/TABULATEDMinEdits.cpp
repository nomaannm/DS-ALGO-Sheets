#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findMinChanges(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
   // Memoization step.
   if (dp[i][j] != -1)
       return dp[i][j];

   // If any of the pointers have reached the end, return appropriate values.
   if (i == s1.length())
   {
       return dp[i][j] = s2.length() - j;
   }
   if (j == s2.length())
   {
       return dp[i][j] = s1.length() - i;
   }

   // If the current characters match, no need of any operation.
   if (s1[i] == s2[j])
   {
       return dp[i][j] = findMinChanges(s1, s2, i + 1, j + 1, dp);
   }

   // Otherwise, any one of the insert, delete or replace operation needs to be performed.

   // Insert operation.
   int x = findMinChanges(s1, s2, i, j + 1, dp);

   // Delete operation.
   int y = findMinChanges(s1, s2, i + 1, j, dp);

   // Replace operation.
   int z = findMinChanges(s1, s2, i + 1, j + 1, dp);

   // Return after adding one to the answer.
   return dp[i][j] = 1 + min(min(x, y), z);
}

int editDistance(string str1, string str2)
{
   int n = str1.length();
   int m = str2.length();
   vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
   return findMinChanges(str1, str2, 0, 0, dp);
}

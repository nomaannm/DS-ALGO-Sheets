class Solution {
public:
    int longestCommonSubsequence(string text1, string text2){
        int maxLength = 0;

        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> matrix(m+1, vector<int>(n+1));

        for(int i=1; i <= m; i++){
            for(int j=1; j <= n; j++){
                if(text1[i-1] == text2[j-1]){
                    matrix[i][j] = matrix[i-1][j-1] + 1;
                    maxLength = max(maxLength, matrix[i][j]);
                } else {
                    matrix[i][j] = max(matrix[i-1][j], matrix[i][j-1]);
                }
            }
        }

        return maxLength;

        
    }
};

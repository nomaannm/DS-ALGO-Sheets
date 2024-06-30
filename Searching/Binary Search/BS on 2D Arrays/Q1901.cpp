class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0, high = mat[0].size() - 1;
        while(low <= high){
            int mid = (low + high)/2;
            int maxRowIndex = maxValue(mat,mat.size(),mat[0].size(),mid);
            int left = (mid-1 >= 0) ? mat[maxRowIndex][mid-1] : -1;
            int right = (mid+1 < mat[0].size()) ? mat[maxRowIndex][mid+1] : -1;
            if(mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
                return {maxRowIndex,mid};
            else if(mat[maxRowIndex][mid] < left) high = mid-1;
            else low = mid+1;
        }

        return {-1,-1};
        
    }

    int maxValue(vector<vector<int>>& matrix, int n, int m, int col){
        int maxValue = INT_MIN;
        int index = -1;
        for(int i = 0; i < n; i++){
            if(matrix[i][col] > maxValue){
                maxValue = matrix[i][col];
                index = i;
            }
        }
        return index;
    }
};

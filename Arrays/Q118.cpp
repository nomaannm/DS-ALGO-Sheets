class Solution {
public:
    vector<int> generateRow(int row){
        vector<int> rowList;
        rowList.push_back(1);
        int ans = 1;
        for(int col = 1; col < row; col++){
            ans *= (row - col);
            ans /= col;
            rowList.push_back(ans); 
        }
        return rowList;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i{1}; i <= numRows; i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};

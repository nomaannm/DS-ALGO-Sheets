class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        set<pair<int,int>> path;

        for(int r = 0; r <= rows; r++){
            for(int c = 0; c <= cols; c++){
                if(dfs(board, r, c, path, 0, word)) return true;
            }
        }

        return false;
        
    }
private:
    bool dfs(vector<vector<char>>& board, int r, int c, set<pair<int,int>>& path, int index, string& word ){
        if(index == word.size()) return true;
        if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || word[index] != board[r][c] || path.count({r,c}) > 0) return false;
        path.insert({r, c});

        // Explore all possible directions
        bool res = (dfs(board, r+1, c, path, index+1, word) ||
                    dfs(board, r-1, c, path, index+1, word) ||
                    dfs(board, r, c+1, path, index+1, word) ||
                    dfs(board, r, c-1, path, index+1, word));

       path.erase({r,c});

       return res;
    }

};

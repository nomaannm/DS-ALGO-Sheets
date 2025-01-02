class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!visited[row][col] && grid[row][col] == '1'){
                    islands++;
                    bfs(row, col, visited, grid);

                }
            }
        }
        return islands;
    }

private:
    void bfs(int r, int c, vector<vector<int>>&vis, vector<vector<char>>& grid )
    {
    vis[r][c]=1;
    queue<pair<int,int>>q;
    q.push({r, c});
    int row=grid.size();
    int col=grid[0].size();
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        for(int k=0;k<4;k++)
        {
        int newrow=r+delrow[k];
        int newcol=c+delcol[k];

        if(newrow>=0 && newrow<row && newcol>=0 && newcol<col && grid[newrow][newcol]=='1' && !vis[newrow][newcol])
        {
            vis[newrow][newcol]=1;
            q.push({newrow,newcol});
        }
        }
        
    }
    }
};




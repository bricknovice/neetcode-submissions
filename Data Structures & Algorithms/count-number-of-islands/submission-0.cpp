class Solution {
public:
    int row;
    int col;
    vector<vector<bool>> visited;
    
    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        //Out of bound or visited or water will early return
        if(r<0 || r>=row || c<0 || c>=col || visited[r][c] || grid[r][c]=='0')
            return;
        
        visited[r][c] = true;
        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int rst=0;
        row = grid.size();
        col = grid[0].size();
        visited.assign(row, vector<bool>(col, false));
        
        for(int i=0;i<row; ++i)
        {
            for(int j=0;j<col; ++j)
            {
                //root of unvisited island
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    rst++;
                    
                }
                    
            }
        }
        return rst;
    }
};

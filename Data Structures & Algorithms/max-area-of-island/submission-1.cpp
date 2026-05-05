class Solution {
public:
    int row;
    int col;
    
    void dfs(vector<vector<int>>& grid, int r, int c, int& cnt)
    {
        //Out of bound or visited or water will early return
        if(r<0 || r>=row || c<0 || c>=col || grid[r][c]==0)
            return;
        
        cnt++;
        grid[r][c] = 0;
        dfs(grid, r+1, c, cnt);
        dfs(grid, r-1, c, cnt);
        dfs(grid, r, c+1, cnt);
        dfs(grid, r, c-1, cnt);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int maxArea = 0;
        for(int i=0;i<row; ++i)
        {
            for(int j=0;j<col; ++j)
            {
                //root of unvisited island
                if(grid[i][j] == 1)
                {
                    int cnt = 0;
                    dfs(grid, i, j, cnt);
                    maxArea = max(cnt, maxArea);
                }
                    
            }
        }
        return maxArea;
    }

};

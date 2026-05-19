class Solution {
public:

    int dir[4][2]
    {
        {0,1},
        {0,-1},
        {-1, 0},
        {1, 0}
    };
    int ROW;
    int COL;

    void dfs(vector<vector<bool>>& _matrix, vector<vector<int>> & heights, int x, int y)
    {

        for(int i=0;i<4; ++i)
        {
            int curx = x+dir[i][0];
            int cury = y+dir[i][1];

            //Not yet visited & cur lower than previous
            if(curx>=0 && curx<ROW && cury>=0 && cury<COL
                && !_matrix[curx][cury] && heights[curx][cury]>=heights[x][y])
            {
                _matrix[curx][cury] = true;
                dfs(_matrix, heights, curx, cury);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROW = heights.size();
        COL = heights[0].size();
        vector<vector<bool>> pacMatrix(ROW, vector<bool>(COL, false));
        vector<vector<bool>> atlanticMatrix(ROW, vector<bool>(COL, false));

        for(int i=0;i<ROW; ++i)
        {
            pacMatrix[i][0]=true;
            atlanticMatrix[i][COL-1]=true;
            dfs(pacMatrix, heights, i, 0);
            dfs(atlanticMatrix, heights, i, COL-1);
        }

        for(int i=0;i<COL; ++i)
        {
            if(!pacMatrix[0][i])
            {
                pacMatrix[0][i]=true;
                dfs(pacMatrix, heights, 0, i);
            }
            if(!atlanticMatrix[ROW-1][i])
            {
                atlanticMatrix[ROW-1][i]=true;
                dfs(atlanticMatrix, heights, ROW-1, i);
            }
        }
        vector<vector<int>> rst;
        for(int i=0;i<ROW; ++i)
        {
            for(int j=0;j<COL; ++j)
            {
                if(pacMatrix[i][j] == 1 && atlanticMatrix[i][j] == 1)
                {
                    rst.push_back({i, j});
                }
            }
        }
        return rst;
    }
};

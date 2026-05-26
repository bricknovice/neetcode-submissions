class Solution {
public:
    int dir[4][2] = 
    {
        {0,1},{0,-1},
        {1,0},{-1,0}
    };
    int COL;
    int ROW;
    void dfs(vector<vector<char>>& board, int x, int y)
    {
        if(x<0 || x>ROW-1 || y<0 || y>COL-1 || board[x][y]=='X' || board[x][y] == 'T')
            return ;
        board[x][y] = 'T';
        for(int i=0;i<4; ++i)
        {
            int curx = x+dir[i][0];
            int cury = y+dir[i][1];
            dfs(board, curx, cury);
        }

     
        return ;
    }
    void solve(vector<vector<char>>& board) {
        ROW = board.size();
        COL = board[0].size();
        for(int i=0;i<ROW; ++i)
        {
            for(int j=0;j<COL; ++j)
            {
                if((i == 0 || i == ROW-1 || j == 0 || j == COL-1))
                    dfs(board, i, j);
            }
        }

        for(int i=0;i<ROW; ++i)
        {
            for(int j=0;j<COL; ++j)
            {
                
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                else if(board[i][j]=='T')
                {
                    board[i][j]='O';
                }
                    
            }
        }
    }
};

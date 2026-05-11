class Solution {
public:
    int dir[4][2]=
    {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };

    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> myqueue;
        int minutes_cnt=0;
        for(int i=0;i<grid.size(); ++i)
        {
            for(int j=0;j<grid[0].size(); ++j)
            {
                if(grid[i][j] == 2)
                    myqueue.push({i,j});
            }
        }

        while(!myqueue.empty())
        {
            int cnt = myqueue.size();
            //All the fruit that will rotten within this minute.
            while(cnt--)
            {
                
                vector<int> curNode = myqueue.front();
                myqueue.pop();
                int x = curNode[0];
                int y = curNode[1];
                grid[x][y] = 2; // current rotten
                for(int i=0;i<4; ++i)
                {
                    int nextx = x + dir[i][0];
                    int nexty = y + dir[i][1];
                    if( nextx>=0 && nextx <grid.size() && nexty >=0 && nexty <grid[0].size()
                        && grid[nextx][nexty] == 1)
                    {
                        grid[nextx][nexty] = 2;
                        myqueue.push({nextx,nexty});
                    }
                     
                }
            }
            if(!myqueue.empty())   
                minutes_cnt++;
        }

        for(int i=0;i<grid.size(); ++i)
        {
            for(int j=0;j<grid[0].size(); ++j)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return minutes_cnt;
    }
};

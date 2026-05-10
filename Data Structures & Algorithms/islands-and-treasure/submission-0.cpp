class Solution {
public:


    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> myqueue;
        for(int i=0;i<grid.size(); ++i)
        {
            for(int j=0;j<grid[0].size(); ++j)
            {
                if(grid[i][j] == 0)
                    myqueue.push(make_pair(i, j));
            }
        }

        vector<pair<int, int>> dir = 
        {
            {0, 1},
            {0, -1},
            {-1, 0},
            {1, 0}
        };

        while(!myqueue.empty())
        {
            pair<int, int> curNode = myqueue.front();
            myqueue.pop();

            for(int i=0;i<dir.size(); ++i)
            {
                int x = curNode.first+dir[i].first;
                int y = curNode.second+dir[i].second;

                if(x<0 || x>=grid.size() 
                    || y<0 || y>=grid[0].size())
                    continue;
                
                if(grid[x][y] == INT_MAX) {
                    grid[x][y] = grid[curNode.first][curNode.second]+1;
                    myqueue.push(make_pair(x, y));
                }
            }
        }

        
        return;
    }
};

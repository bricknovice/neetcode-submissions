class Solution {
public:
    vector<vector<int>> memo;
    int dfs(vector<vector<int>>& memo, int x, int y)
    {
        if(x == memo.size()-1 && y == memo[0].size()-1)
            return 1;
        else if(x >= memo.size() || y >= memo[0].size())
            return 0;
        if(memo[x][y]!=-1)  return memo[x][y];
        memo[x][y] = dfs(memo, x+1, y) + dfs(memo, x, y+1);
        return memo[x][y];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return dfs(memo, 0, 0);
    }
};

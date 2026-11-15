class Solution {
public:
    vector<vector<int>> memo;
    int dfs(string& t1, string& t2, int i, int j)
    {
        if(i>=t1.size() || j>=t2.size())    return 0;
        vector<int> tmp(4, 0);
        if(memo[i][j]!=-1)  return  memo[i][j];
        if(t1[i] == t2[j])
        {
            tmp[0] = dfs(t1, t2, i+1, j+1)+1;
        }
        tmp[1] = dfs(t1, t2, i+1, j);
        tmp[2] = dfs(t1, t2, i, j+1);
        tmp[3] = dfs(t1, t2, i+1, j+1);
        memo[i][j] = *max_element(tmp.begin(), tmp.end());
        return memo[i][j];


    }
    int longestCommonSubsequence(string text1, string text2) {
        memo.assign(text1.size(), vector<int>(text2.size(), -1));
        return dfs(text1, text2, 0, 0);
    }
};

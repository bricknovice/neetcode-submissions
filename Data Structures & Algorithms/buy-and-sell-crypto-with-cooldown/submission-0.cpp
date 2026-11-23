class Solution {
public:
    vector<vector<int>> memo;
    int dfs(vector<int>& prices, vector<vector<int>>& memo, int idx, bool is_hold)
    {
        if(idx >= prices.size()){
            return 0;
        }
        if(memo[idx][is_hold]!=-1)  return memo[idx][is_hold];

        if(is_hold)
        {
            //Take max of sell or keep
            memo[idx][is_hold] = max(dfs(prices, memo, idx+2, 0)+prices[idx], dfs(prices, memo, idx+1, 1));
        }else
        {
            //Take max of Buy or skip
            memo[idx][is_hold] = max(dfs(prices, memo, idx+1, 1)-prices[idx], dfs(prices, memo, idx+1, 0));
        }
        return memo[idx][is_hold];

    }
    int maxProfit(vector<int>& prices) {
        memo.assign(prices.size(), vector<int>(2, -1));
        return dfs(prices, memo, 0, 0);
    }
};

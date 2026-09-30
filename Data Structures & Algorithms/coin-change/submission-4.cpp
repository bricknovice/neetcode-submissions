class Solution {
public:
    unordered_map<int, int> memo; 
    int dp(vector<int>& coins, int amount)
    {
        if(amount == 0) return 0;

        if(memo.find(amount)!=memo.end())
            return memo[amount]; 

        int rst = INT_MAX;
        for(int i=0; i<coins.size(); ++i)
        {
            if(amount - coins[i] >= 0)
            {
                int result = dp( coins, amount-coins[i]);
                if(result != INT_MAX){
                    rst = min(rst , 1+result);
                }
            }
            
        }
        memo[amount] = rst;
        return rst;
    }

    int coinChange(vector<int>& coins, int amount) {
        int cnt = dp(coins, amount);
        return cnt == INT_MAX ? -1 : cnt;
    }
};

class Solution {
public:
    vector<vector<int>> memo;
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memo.assign(n + 1, vector<int>(n, -1));
        return dfs(nums, -1, 0);
    }

    int dfs(vector<int>& nums, int prev, int cur)
    {
        if(cur==nums.size())
        {
            return 0;
        }

        if (memo[prev + 1][cur] != -1) return memo[prev + 1][cur];
        int res = dfs(nums, prev, cur + 1);                       // skip
        if (prev == -1 || nums[prev] < nums[cur])
            res = max(res, 1 + dfs(nums, cur, cur + 1));          // take

        return memo[prev + 1][cur] = res;
    }
};

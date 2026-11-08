class Solution {
public:
     set<pair<int,int>> memo;
    bool dfs(vector<int>& nums, int idx, int remain)
    {
        if(remain == 0) return true;
        if (remain < 0 || idx >= nums.size()) return false;
        
        if (memo.count({idx, remain})) return false;
        //Take idx
        if(dfs(nums, idx+1, remain-nums[idx]))
            return true;
        //Not take idx
        if(dfs(nums, idx+1, remain))
            return true;

        memo.insert({idx, remain});
        return false;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        //If odd, no way we have two subsets that is identical. therefore impossible.
        if(totalSum&1)  return false;
        return dfs(nums, 0, totalSum/2);
    }
};

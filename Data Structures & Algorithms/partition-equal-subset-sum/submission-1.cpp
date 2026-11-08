class Solution {
public:
    set<int> memo;
    bool dfs(vector<int>& nums, int idx, int remain)
    {
        if(idx>=nums.size())
        {
            return false;
        }
        if(remain == nums[idx]) return true;
        if(memo.find(remain) != memo.end())
            return false;
        //Take idx
        if(dfs(nums, idx+1, remain-nums[idx]))
            return true;
        //Not take idx
        if(dfs(nums, idx+1, remain))
            return true;

        memo.insert(remain);
        return false;
    }

    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(const auto &n: nums)
        {
            totalSum+=n;
        }
        //If odd, no way we have two subsets that is identical. therefore impossible.
        if(totalSum&1)  return false;
        return dfs(nums, 0, totalSum/2);
    }
};

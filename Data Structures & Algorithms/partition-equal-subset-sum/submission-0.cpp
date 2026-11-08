class Solution {
public:
    bool dfs(vector<int>& nums, int idx, int remain)
    {
        if(idx>=nums.size())
        {
            return false;
        }
        if(remain == nums[idx]) return true;

        //Take idx
        if(dfs(nums, idx+1, remain-nums[idx]))
            return true;
        //Not take idx
        if(dfs(nums, idx+1, remain))
            return true;
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

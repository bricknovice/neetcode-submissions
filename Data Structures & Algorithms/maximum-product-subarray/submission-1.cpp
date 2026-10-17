class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int rst = nums[0];
        int curMin = 1, curMax = 1;

        for(int num: nums)
        {
            int tmp = curMax*num;
            curMax = max(max(num*curMax, num*curMin),num );
            curMin = min(min(tmp, num*curMin),num );
            rst = max(rst, curMax);
        }
        return rst;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)  return nums[0];
        int ll = nums[0];
        int l = nums[1];
        vector<int> tmpmax(nums.size());
        tmpmax[0] = ll;
        tmpmax[1] = max(l, ll);
        for(int i=2; i<nums.size(); ++i)
        {
            int tmpl = nums[i] + tmpmax[i-2];
            tmpmax[i] = max(l, tmpl);
            ll = l;
            l = tmpl;
        }
        return tmpmax[nums.size()-1];
    }
};

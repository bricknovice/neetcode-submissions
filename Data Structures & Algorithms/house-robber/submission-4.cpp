class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)  return nums[0];
        int ll = nums[0];
        int l = nums[1];
        vector<int> tmpmax(nums.size());
        int recmaxll = ll;
        int recmaxl = max(l, ll);
        for(int i=2; i<nums.size(); ++i)
        {
            int tmpl = nums[i] + recmaxll;
            int tmprecmaxl = recmaxl;
            recmaxl = max(l, tmpl);
            recmaxll = tmprecmaxl;
            ll = l;
            l = tmpl;
        }
        return recmaxl;
    }
};

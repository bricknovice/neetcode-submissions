class Solution {
public:
    int climbStairs(int n) {
        if(n==1)    return 1;
        if(n==2)    return 2;
        vector<int> s(n+1);
        s[1] = 1;
        s[2] = 2;
        for(int i=3; i<=n; ++i)
        {
            s[i] = s[i-1] + s[i-2];
        }
        return s[n];
    }
};

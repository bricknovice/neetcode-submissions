class Solution {
public:
    vector<int> sum;
    int dfs(string& s, int idx){
        if(idx == s.size()) return 1;
        else if(idx<s.size()){
            if(sum[idx]!= -1 )  return sum[idx];
            if(s[idx] == '0')   return 0;
            sum[idx] = 0;
            sum[idx] += dfs(s, idx+1);
            if((idx+1<s.size()) && (s[idx]=='1' || (s[idx]=='2' && s[idx+1]<='6')))
                sum[idx] += dfs(s, idx+2);
            return sum[idx];
        }
            return 0;
    }
    int numDecodings(string s) {
        sum.assign(s.size(), -1);
        return dfs(s, 0);
    }
};

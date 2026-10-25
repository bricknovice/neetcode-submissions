class Solution {
public:
    unordered_map<int, bool> used;
    //Why dic over vector? dic can present not visited, visited but no match, visited & match.
    bool wordBreak(string s, vector<string>& wordDict) {
        used[s.length()] = true;
        return dfs(s, wordDict, 0);
    }

    bool dfs(string& s, vector<string>& wordDict, int idx)
    {
        if(used.find(idx) != used.end())
            return used[idx];
        
        for(auto& w: wordDict)
        {
            if(idx + w.length()<=s.length() && 
                s.substr(idx, w.length()) == w)
                {
                    if(dfs(s, wordDict, idx+w.length()))
                    {
                        used[idx] = true;
                        return true;
                    }

                }
        }
        used[idx] = false;
        return false;
    }
};

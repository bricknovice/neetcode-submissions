class Solution {
public:
    unordered_map<char, set<char>> adj;
    unordered_map<char, bool> visited;
    string result;
    string foreignDictionary(vector<string>& words) {
        //1. Get adjlist from words
        for (const auto& word : words) {
            for (char ch : word) {
                adj[ch];
            }
        }
        for(int i=1;i<words.size(); ++i)
        {
            int minlen = min(words[i-1].size(), words[i].size());
            //Violation
            if(words[i-1].size() > words[i].size() && words[i-1].substr(0, minlen) == words[i].substr(0, minlen))
                return "";
            for(int j=0; j<minlen; ++j)
            {
                if(words[i-1][j] != words[i][j])
                {
                    adj[words[i-1][j]].insert(words[i][j]);
                    break;
                }
            }
        }

        for(const auto& pair: adj)
        {
            if(dfs(pair.first))
                return "";
        }

        reverse(result.begin(), result.end());
        return result;
       
    }

    bool dfs(char ch)
    {
        if (visited.find(ch) != visited.end()) {
            return visited[ch];
        }

        visited[ch] = true;

        for(char next: adj[ch])
        {
            if (dfs(next)) {
                return true;
            }
        }

        visited[ch] = false;
        result.push_back(ch);
        return false;

    }
};

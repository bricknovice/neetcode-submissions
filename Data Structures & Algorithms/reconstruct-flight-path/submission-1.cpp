class Solution {
public:
    unordered_map<string, vector<string>> adj;
    unordered_map<string, int> idx;
    vector<string> rst;
    void dfs(string curNode){
            
            while(idx[curNode] < adj[curNode].size())
            {
                dfs(adj[curNode][idx[curNode]++]);
            }
            rst.push_back(curNode);
        }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        

        sort(tickets.begin(), tickets.end());
        for(int i=0; i<tickets.size(); ++i)
        {
            adj[tickets[i][0]].push_back(tickets[i][1]);
        }

        for (auto& [from, dests] : adj)
            sort(dests.begin(), dests.end());      // lexical order => smallest path

        dfs("JFK");
        reverse(rst.begin(), rst.end());       // post-order gives it backwards
        return rst;
    }
};

class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;

    bool dfs(int cur, int parent)
    {
        if(visited[cur])
        {
            return false;   //cycle detect
        }
        visited[cur] = true;
        for(int i=0;i<adj[cur].size(); ++i)
        {
            if(adj[cur][i] == parent) //Do not go back to parent, skip
                continue;
            if(!dfs(adj[cur][i], cur))
                return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        visited.assign(n, false);
        for(int i=0;i<edges.size(); ++i)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }


        if(!dfs(0, -1))
            return false;

        int cnt=0;
        for(int i=0;i<n; ++i)
        {
            if(visited[i])  cnt++;
        }
        
        return cnt==n ? true : false;
    }
};

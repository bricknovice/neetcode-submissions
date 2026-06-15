class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> adj;

    void dfs(int cur)
    {
        if(visited[cur])
            return;
        visited[cur] = true;
        for(int i=0; i<adj[cur].size(); ++i)
        {
            dfs(adj[cur][i]);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        visited.resize(n, 0);
        for(int i=0;i<edges.size(); ++i)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int rst_cnt = 0;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                rst_cnt++;
                dfs(i);
            }
        }
        return rst_cnt;
    }
};

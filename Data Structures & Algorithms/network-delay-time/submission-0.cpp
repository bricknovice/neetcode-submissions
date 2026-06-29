class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // From node_num, To Node_num, path weight
        unordered_map<int, vector<pair<int, int>>> adj;
        auto cmp = [](const pair<int,int>& a, const pair<int,int>& b){
            return a.second > b.second;            // min-heap by distance
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> minHeap(cmp);

        unordered_map<int, bool> visited;
        for(int i=0;i<times.size(); ++i)
        {
            adj[times[i][0]].emplace_back(make_pair(times[i][1], times[i][2]));
        }

        for(int i=1; i<=n; ++i)
        {
            visited[i]=false;
        }
        
        //k as start node, first in the minHeap
        minHeap.push({k, 0});

        int t=0;
        while(!minHeap.empty())
        {
            pair<int, int> cur = minHeap.top();
            minHeap.pop();
            if(visited[cur.first])    continue;
            visited[cur.first] = true;
            t = max(t, cur.second);
            if(adj.count(cur.first))
            {
                for(int i=0; i<adj[cur.first].size(); ++i)
                {
                    pair<int, int> dst = adj[cur.first][i];
                    if(!visited[dst.first])
                        minHeap.push({dst.first, cur.second + dst.second });
                }
            }

        }
        for(int i=1;i<=n ; ++i)
        {
            if(!visited[i]) return -1;
        }
        return t;
    }
};

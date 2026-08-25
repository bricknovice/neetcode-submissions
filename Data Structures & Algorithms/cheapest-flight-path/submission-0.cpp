class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        vector<vector<pair<int, int>>> adj(n);
        for(const auto& flight: flights)
        {
            adj[flight[0]].emplace_back(flight[1],flight[2]);
        }

        queue<tuple<int, int, int>> q;

        q.push({0, src, 0});

        while(!q.empty())
        {
            auto [cst, node, stops] = q.front();
            q.pop();

            if(stops > k) continue;

            for(auto const & neightbor: adj[node])
            {
                int nei = neightbor.first, w = neightbor.second;

                if(cst + w < prices[nei])
                {
                    prices[nei] = cst + w;
                    q.push({prices[nei], nei, stops+1});
                }
            }
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};

class DSU{
public:
    vector<int> parent, Size;
    DSU(int n): parent(n+1), Size(n+1, 1)
    {
        for(int i=0; i<=n; ++i)
            parent[i]=i;
    }

    int find(int node)
    {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    bool unionsets(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return false;
        if(Size[pu] < Size[pv])
            swap(pu, pv);
        parent[pv] = pu;
        Size[pu] += Size[pv];
        return true;
    }
};

class Solution {
public:


    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        DSU dsu(n);
        vector<array<int, 3>> edges;

        for(int i=0;i<n; ++i)
        {
            for(int j=i+1; j<n; ++j)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());
        int w = 0;
        int cnt=n-1;
        for(int i=0; i<edges.size(); ++i)
        {
            if(cnt==0)  break;
            if(dsu.unionsets(edges[i][1], edges[i][2]))
                w+=edges[i][0];
        }
        return w;
    }
};

class DSU {
public:
    vector<int> parent; 
    vector<int> rank;
    DSU(int n)
    {
        parent = vector<int>(n+1);
        rank = vector<int>(n+1, 1);
        for(int i=1; i<=n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int node)
    {
        while(node != parent[node])
        {
            parent[node] = parent[parent[node]];    //cur link to parent to grandparent
            node = parent[node];
        }
        return node;
    }

    bool unionset(int na, int nb)
    {
        int ra = find(na);
        int rb = find(nb);
        if(ra == rb)
            return false;
        if(rank[ra]<rank[rb])
        {
            swap(ra, rb);
        }
        parent[rb] = ra;
        rank[ra]+=rank[rb];
        return true;
    }
};

class Solution {
public:

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        int a=-1, b=-1;
        for(int i=0;i<edges.size(); ++i)
        {
            if(!dsu.unionset(edges[i][0], edges[i][1]))
            {
                a = edges[i][0];
                b = edges[i][1];
                break;
            }
        }
        return {a, b};
    }
};

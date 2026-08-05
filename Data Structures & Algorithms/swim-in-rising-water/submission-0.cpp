class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N =grid.size();
        set<pair<int, int>> visit;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        vector<vector<int>> dir = {
            {0, 1}, {0, -1},
            {1, 0}, {-1, 0}
        };

        minHeap.push({grid[0][0], 0, 0});
        visit.insert({0, 0});

        while(!minHeap.empty())
        {
            auto cur = minHeap.top();
            minHeap.pop();

            if(cur[1] == N-1 && cur[2] == N-1)
                return cur[0];
            
            for(const auto& d: dir)
            {
                int nR = cur[1]+d[0], nC = cur[2]+d[1];
                if(nR<0 || nC<0 || nR>N-1 || nC>N-1 || visit.count({nR, nC}))
                    continue;
                visit.insert({nR, nC});
                minHeap.push({max(cur[0], grid[nR][nC]), nR, nC});
            }
        }
        return N*N;
    }
};

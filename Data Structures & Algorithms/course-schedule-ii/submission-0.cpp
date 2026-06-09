class Solution {
public:
    vector<int> output;

    bool dfs(vector<vector<int>>& prereq, vector<int>& visited, int cur)
    {
        if(visited[cur]==1)       return false;  // Meet cycle
        if(visited[cur]==2)     return true;  //   This graph is finished, skip it.

        visited[cur] = 1;
        for(int i=0;i<prereq[cur].size(); ++i)
        {
            if(!dfs(prereq, visited, prereq[cur][i]))
                return false;
        }
        visited[cur] = 2;   //travse finish
        output.push_back(cur);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> prereq(numCourses);
        vector<int> visited(numCourses, 0); //0: unvisited, 1: cur, 2: finished, 
        
        for(int i=0;i<prerequisites.size(); ++i)
        {
            prereq[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i=0;i<numCourses; ++i)
        {
           if(!dfs(prereq, visited, i))  return {};
        }
        
        return output;
    }
};

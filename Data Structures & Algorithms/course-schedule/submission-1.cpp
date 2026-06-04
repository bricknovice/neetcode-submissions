class Solution {
public:
    
    bool dfs(int course, vector<vector<int>>& adjlist, vector<int>& visited)
    {
        //Detect a loop
        if(visited[course])
            return false;
        visited[course]++;
        for(int i=0;i< adjlist[course].size(); ++i)
        {
            if(!dfs(adjlist[course][i], adjlist, visited))
                return false;
        }
        visited[course] = 0;
        adjlist[course].clear();
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, false);
        vector<vector<int>> adjlist(numCourses);
        //1. Establish adjlist
        for(int i=0;i<prerequisites.size(); ++i)
        {
            adjlist[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i=0;i<numCourses; ++i)
        {
            if(!dfs(i, adjlist, visited))
                return false;
        }
        return true;
    }
};

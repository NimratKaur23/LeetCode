#include<unordered_map>
#include<list>
#include<queue>
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //adj list
        unordered_map<int, list<int>> adj;
        for(int i=0;i<prerequisites.size();i++) {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            adj[u].push_back(v);
        }

        vector<int> indegree(numCourses);
        for(auto i:adj) {
            for(auto j:i.second) {
                indegree[j]++;
            }
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }

        //BFS
        int count=0;

        while(!q.empty()) {
            int frontnode=q.front();
            q.pop();
            count++;

            for(auto neigh:adj[frontnode]) {
                indegree[neigh]--;
                if(indegree[neigh]==0) {
                    q.push(neigh);
                }
            }
        }

        if(count==numCourses)
          return true;
        else
          return false;


    }
};
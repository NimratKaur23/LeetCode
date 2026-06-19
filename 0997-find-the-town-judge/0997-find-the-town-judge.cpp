class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        int ans=-1;

        //adj list
        unordered_map<int,list<int>> adj;
        for(int i=0;i<trust.size();i++) {
            int u=trust[i][0];
            int v=trust[i][1];

            adj[u].push_back(v);
        }

        //indegree
        vector<int> indegree(n+1,0);
        for(auto i:adj) {
            for(auto j:i.second) {
                indegree[j]++;
            }
        }

     for(int i=1;i<=n;i++) {
        if((adj[i].empty()) && (indegree[i]==n-1)) {
            ans= i;
        }
     }

     return ans;
        
    }
};
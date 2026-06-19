class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        int ans=0;

        //adj list
        unordered_map<int, list<int>> adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(auto i:adj) {
           if(i.second.size()!=1) {
            ans=i.first;
           }
        }

        return ans;
        
    }
};
class Solution {
public:
bool dfs(int src, int dest, vector<bool> &visited, unordered_map<int,list<int>> &adj) {

    if(src==dest) {
         return true;
    }

    visited[src]=true;

    for(auto neigh:adj[src]) {
        if(!visited[neigh]) {
           if(dfs(neigh,dest,visited,adj)) {
            return true;
           }
        }
    }

    return false;
}
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {

        // adj list
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n,false);

        return dfs(source,destination,visited,adj);

        return false;
    }
};
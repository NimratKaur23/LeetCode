class Solution {
public:
bool ans=true;
void dfs(vector<vector<int>> &graph,int node,int c,vector<int> &color) {
    color[node]=c;

    for(int i=0;i<graph[node].size();i++) {
        int neigh=graph[node][i];

        //contradiction
        if(color[neigh]!=-1 && color[neigh]==c)
          ans=false;
        
        if(color[neigh]==-1)
          dfs(graph,neigh,1-c,color);
    }

    return;
}

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++) {
            if(color[i]==-1)
              dfs(graph,i,0,color);
        }

        return ans;
    }
};
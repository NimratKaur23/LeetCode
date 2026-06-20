class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        vector<vector<int>> adj(n);
     //  unordered_map<int,list<int>> adj(n);

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(isConnected[i][j]) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> visited(n,0);
        int provinces=0;

        for(int i=0;i<n;i++) {
            if(visited[i])
              continue;
            
            provinces++;

            queue<int> q;
            q.push(i);
            visited[i]=1;

            while(!q.empty()) {
                int node=q.front();
                q.pop();

                for(int neigh:adj[node]) {
                    if(!visited[neigh]) {
                        visited[neigh]=1;
                        q.push(neigh);
                    }
                }
            }
        }
return provinces;

    }
};
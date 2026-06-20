class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //adj list
        unordered_map<int, list<pair<int,int>>> adj;
        for(int i=0;i<flights.size();i++) {
            int u=flights[i][0];
            int v=flights[i][1];
            int d=flights[i][2];

            adj[u].push_back(make_pair(v,d));
        }

        vector<int> distance(n,INT_MAX);

        queue<pair<int,int>> q;

        q.push({src,0});
        distance[src]=0;

       int  steps=0;

        while(!q.empty() && steps<=k) {
            int N=q.size();

            while(N--) {
            int frontnode=q.front().first;
            int d=q.front().second;
            q.pop();

            for(pair<int,int> &neigh:adj[frontnode]) {
                int v=neigh.first;
                int cost=neigh.second;

                if(distance[v]> d+cost) {
                    distance[v]=d+cost;
                    q.push({v,d+cost});
                }
            }
            }

            steps++;
        }

        if(distance[dst]==INT_MAX)
          return -1;
        else
          return distance[dst];
    }
};
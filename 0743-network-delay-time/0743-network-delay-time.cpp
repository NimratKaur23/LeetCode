class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans=INT_MIN;
        vector<int> distance(n,INT_MAX);
        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<times.size();i++) {
            int src=times[i][0];
            int dest=times[i][1];
            int wt=times[i][2];

            adj[src-1].push_back({dest-1,wt});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;

        distance[k-1]=0;
        pq.push({distance[k-1],k-1});

        while(!pq.empty()) {
            pair<int,int> p=pq.top();
            pq.pop();

            int d=p.first;
            int node=p.second;

            if(d>distance[node])
              continue;
            
            for(int i=0;i<adj[node].size();i++) {
                int neigh=adj[node][i].first;
                int wt=adj[node][i].second;

                if(d+wt<distance[neigh]) {
                    distance[neigh]=d+wt;
                    pq.push({d+wt,neigh});
                }
            }
        }

        for(int i=0;i<distance.size();i++) {
            if(distance[i]==INT_MAX)
              return -1;
            
            ans=max(ans,distance[i]);
        }

        return ans;
    }
};
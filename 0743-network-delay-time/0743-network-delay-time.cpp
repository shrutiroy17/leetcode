class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            vector<int>t = times[i];
            int src = t[0];
            int dest = t[1];
            int wt = t[2];
            adj[src].push_back({dest,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dist[k] = 0;
        while(!pq.empty()){
            pair<int,int>p = pq.top();
            pq.pop();
            int node = p.second;
            int d = p.first;
            if(d>dist[node]) continue;
            for(int i=0;i<adj[node].size();i++){
                int neigh = adj[node][i].first;
                int wt = adj[node][i].second;
                if(d+wt<dist[neigh]){
                    dist[neigh] = d+wt;
                    pq.push({d+wt,neigh});
                }
            }
        }
        int res = INT_MIN ;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            res = max(res,dist[i]);
        }
        return res;
    }
};
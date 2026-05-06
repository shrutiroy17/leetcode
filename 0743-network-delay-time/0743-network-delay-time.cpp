class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<times.size();i++){
            int src = times[i][0]-1;
            int dest = times[i][1]-1;
            int wt = times[i][2];
            adj[src].push_back({dest,wt});
        }
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
        pq.push({0,k-1});
        vector<int>dist(n,INT_MAX);
        dist[k-1] = 0;
        while(!pq.empty()){
            pair<int,int>p = pq.top();
            pq.pop();
            int d = p.first;
            int node = p.second;
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
        int res = 0;
        for(int i=0;i<dist.size();i++){
            if(dist[i]==INT_MAX) return -1;
            res = max(res,dist[i]);
        }
        return res;
    }
};
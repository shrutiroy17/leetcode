class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;
        for(auto & p : points){
            int x = p[0];
            int y = p[1];
            int dist = (x*x)+(y*y);
            if(pq.size()<k){
                pq.push({dist,{x,y}});
            }
            else if(dist<pq.top().first){
                pq.pop();
                pq.push({dist,{x,y}});
            }
        }
        vector<vector<int>>res;
        while(!pq.empty()){
            res.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return res;
    }
};
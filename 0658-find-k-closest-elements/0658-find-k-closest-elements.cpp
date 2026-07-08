class Solution {
public:
    struct cmp{
        bool operator() (const pair<int,int>& a, const pair<int,int>& b){
            if(a.first!=b.first) return a.first<b.first; // map heap automated
            return a.second>b.second;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        //heap holds distance,point
        for(int p : arr){
            int dist = abs(x-p);
            if(pq.size()<k){
                pq.push({dist,p});
            }
            else if(dist<pq.top().first || (dist==pq.top().first && p<pq.top().second)){
                pq.pop();
                pq.push({dist,p});
            }
        }
        vector<int>res;
        while(!pq.empty()){
            res.push_back(pq.top().second); // since it is a max heap so res will be in descending order
            pq.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};
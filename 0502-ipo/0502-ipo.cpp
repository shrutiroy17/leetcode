class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        int i;
        vector<pair<int,int>>proj;
        priority_queue<int>pq;
        for(i=0;i<n;i++){
            proj.push_back({capital[i],profits[i]});
        }
        sort(proj.begin(),proj.end());
        // you have cap->profit now 
        int idx = 0;
        while(k--){
            while(idx<n){
                if(proj[idx].first>w) break;
                pq.push(proj[idx].second);
                idx++;
            }
            if(pq.empty()) return w;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};
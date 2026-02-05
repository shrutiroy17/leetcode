class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
             return a.first < b.first;
        }
    };
    
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        for(int i=0;i<n;i++){
            int sc = score[i];
            int pos = i;
            pq.push({sc,pos});
        }
        int rank = 1;
        vector<string>res(n);
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            if(rank==1){
                res[p.second] = "Gold Medal";
            }
            else if(rank==2){
                res[p.second] = "Silver Medal";
            }
            else if(rank==3){
                res[p.second] = "Bronze Medal";
            }
            else {
                res[p.second] = to_string(rank);
            }
            rank++;
        }
        return res;
    }

};
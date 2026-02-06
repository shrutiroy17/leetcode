class Solution {
public:
    struct cmp{
        bool operator()(pair<int,string>&a,pair<int,string>&b){
            return a.first<b.first;
        }
    };
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        //maintain max heap with height,name 
        //pop as per name 
        int n = names.size();
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        for(int i=0;i<n;i++){
            pq.push({heights[i],names[i]});
        }
        vector<string>res;
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            res.push_back(x.second);
        }
        return res;
    }
};
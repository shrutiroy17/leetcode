class Solution {
public:
    struct cmp{
        bool operator () (const pair<int,string>&a,const pair<int,string>&b){
            if(a.first!=b.first) return a.first>b.first;
            return a.second<b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string,int>freq;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        for(auto w : words){
            freq[w]++;
        }
        for(auto x: freq){
            string word = x.first;
            int count = x.second;
            pair<int,string>p = {count,word};
            if(pq.size()<k) pq.push(p);
            else if(count>pq.top().first || count==pq.top().first && word<pq.top().second ){
                pq.pop();
                pq.push(p);
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
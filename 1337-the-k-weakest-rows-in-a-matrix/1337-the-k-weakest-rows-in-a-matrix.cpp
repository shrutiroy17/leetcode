class Solution {
public:
    int fun(vector<vector<int>>& mat, int i,int m){
        int count = 0 ;
        for(int j=0;j<m;j++){
            if(mat[i][j]==1) count++;
        }
        return count;
    }
    struct cmp{
        bool operator() (const pair<int,int>& a, const pair<int,int>& b){
            if(a.first!=b.first)
            return a.first<b.first; // max heap automated
            return a.second<b.second;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq; //count,i
        for(int i=0;i<n;i++){
            int count1 = fun(mat,i,m);
            if(pq.size()<k){
                pq.push({count1,i});
            }
            else if(count1<pq.top().first || count1==pq.top().first && i<pq.top().second){
                pq.pop();
                pq.push({count1,i});
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
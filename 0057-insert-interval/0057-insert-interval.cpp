class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& inter){
        if (inter.empty()) return {};
        sort(inter.begin(), inter.end());
        vector<vector<int>> final;
        int n = inter.size();
        int start = inter[0][0];
        int end = inter[0][1];
        for(int i=1;i<n;i++){
            if(end>=inter[i][0]) end = max(end,inter[i][1]);
            else{
                final.push_back({start,end});
                start = inter[i][0];
                end = inter[i][1];
            }
        }
        final.push_back({start,end});
        return final;
    }
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ni) {
        vector<vector<int>> ans;
        int n = in.size();
        bool push = false;
        for(int i=0;i<n;i++){
            int start = in[i][0];
            if(push==false && start>=ni[0]){
                ans.push_back(ni);
                push = true;
            }
            ans.push_back(in[i]);
        }
        if(push==false) ans.push_back(ni);
        // now merge is needed 
        return mergeIntervals(ans);
    }
};
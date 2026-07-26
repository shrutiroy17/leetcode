class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string,int>mpp;
        for(int i=0;i<n;i++){
            mpp[wordList[i]] = i ;
        }
        if(mpp.find(begin)==mpp.end()){
            mpp[begin]++;
        }
        if(mpp.find(end)==mpp.end()) return 0;
        queue<pair<string,int>>q;
        q.push({begin,1});
        mpp.erase(begin);
        while(!q.empty()){
            pair<string,int>p = q.front();
            q.pop();
            string s = p.first;
            int val = p.second;
            if(s==end) return val;
            for(int i=0;i<s.size();i++){
                char c = s[i];
                for(int j=97;j<=122;j++){
                    if(c==j) continue;
                    s[i] = j;
                    if(mpp.find(s)!=mpp.end()){
                        q.push({s,val+1});
                        mpp.erase(s);
                    }
                }
                s[i] = c;
            }
        }
        return 0;
    }
};
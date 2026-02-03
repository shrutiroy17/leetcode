class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>pq;
        string res = "";
        int seat = 0;
        unordered_map<char,int>f;
        for(char c : s){
            f[c]++;
        }
        //now push hash map data into max heap
        for(auto& x:f){
            pq.push({x.second,x.first});
        }
        //now check which letter you need to push and pop
        while(!pq.empty()){
            pair<int,char>p = pq.top(); //p={freq,el}
            pq.pop();
            if(seat==0 || res[seat-1]!=p.second){
                res += p.second;
                seat++;
                p.first--;
                if(p.first>0) pq.push(p);
            }
            else{
                //push 2nd largest freq el 
                if(pq.empty()) return "";
                pair<int,char>p2 = pq.top();
                pq.pop();
                res += p2.second;
                seat++;
                p2.first--;
                if(p2.first>0) pq.push(p2);
                pq.push(p);
            }
        }
        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mpp;
        unordered_map<char,int> nextFree;
        for(char task : tasks){
            mpp[task]++;
            nextFree[task] = 1; 
        }
        priority_queue<pair<int,char>> pq;
        for(auto &it : mpp){
            pq.push({it.second, it.first});
        }
        int seat = 1;  
        while(!pq.empty()){
            vector<pair<int,char>> temp;
            while(!pq.empty()){
                auto top = pq.top();
                pq.pop();
                int freq = top.first;
                char task = top.second;
                if(nextFree[task] <= seat){
                    freq--;  
                    if(freq > 0){
                        pq.push({freq, task});
                    }
                    nextFree[task] = seat + n + 1;
                    break;
                }
                else{
                    temp.push_back({freq, task});
                }
            } 
            for(auto &p : temp){
                pq.push(p);
            }
            seat++;
        }
        return seat - 1;
    }
};
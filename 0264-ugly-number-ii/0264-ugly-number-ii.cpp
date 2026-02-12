class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        unordered_set<long long>visited;
        pq.push(1);
        visited.insert(1);
        long long curr = 0;
        for(int i=0;i<n;i++){
            curr = pq.top();
            pq.pop();
            if(!visited.count(curr*2)){
                pq.push(curr*2);
                visited.insert(curr*2);
            }
            if(!visited.count(curr*3)){
                pq.push(curr*3);
                visited.insert(curr*3);
            }
            if(!visited.count(curr*5)){
                pq.push(curr*5);
                visited.insert(curr*5);
            }
        }
        return (int)curr;
    }
};
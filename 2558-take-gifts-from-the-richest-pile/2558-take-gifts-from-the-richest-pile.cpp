class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(int g : gifts){
            pq.push(g);
        }
        while(k--){
            long long maxEl = pq.top();
            pq.pop();
            long long sqMax = floor(sqrt(maxEl));
            pq.push(sqMax);
        }
        long long sum = 0;
        while(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};
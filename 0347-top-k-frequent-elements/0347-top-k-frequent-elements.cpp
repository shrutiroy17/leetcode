class Solution {
public:
    struct cmp {
        bool operator()(pair<int,int>& a, pair<int,int>& b) {
            return a.first > b.first; // min-heap by frequency
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> f;
        for(int x : nums) {
            f[x]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

        for(auto &i : f) {
            int el = i.first;
            int freq = i.second;
            pair<int,int> curr = {freq, el};

            if(pq.size() < k) {
                pq.push(curr);
            }
            else if(freq > pq.top().first) {
                pq.pop();
                pq.push(curr);
            }
        }

        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(char c : s){
            freq[c]++;
        }
        // convert hashmap to vector of pairs
        vector<pair<char,int>>v(freq.begin(),freq.end());
        //sort on the basis of second value of pair
        sort(v.begin(),v.end(),[](auto &a,auto &b){
            return a.second>b.second;
        });
        //find final result 
        string ans;
        for(auto &p:v){
            ans+=string(p.second,p.first);
        }
        return ans;
    }
};
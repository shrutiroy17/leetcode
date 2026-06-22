class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>have;
        for(char t : text){
            have[t]++;
        }
        unordered_map<char,int>need;
        need['b']=1;
        need['a']=1;
        need['l']=2;
        need['o']=2;
        need['n']=1;
        int res = INT_MAX;
        return min({have['b'],have['a'],have['l']/2,have['o']/2,have['n']});
    }
};
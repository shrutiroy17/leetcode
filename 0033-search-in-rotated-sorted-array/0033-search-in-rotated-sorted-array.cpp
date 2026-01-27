class Solution {
public:
    int search(vector<int>& v, int t) {
        int n = v.size();
        int l = 0;
        int h = n - 1;
        int smallest = 0;
        while (l <= h) {
            int g = (l + h) / 2;
            if (v[g] > v[n - 1])
                l = g + 1;
            else {
                smallest = g;
                h = g - 1;
            }
        }
        // now you have smallest i.e the partition index
        l = 0;
        h = smallest - 1;
        // find if target is in left part
        while (l <= h) {
            int g = (l + h) / 2;
            if (v[g] == t)
                return g;
            else if (v[g] > t)
                h = g - 1;
            else
                l = g + 1;
        }
        l = smallest, h = n - 1;
        while (l <= h) {
            int g = (l + h) / 2;
            if (v[g] == t)
                return g;
            else if (v[g] > t)
                h = g - 1;
            else
                l = g + 1;
        }
        return -1;
    }
};
class Solution {
public:
    long long mergeSort(vector<int>& pref, int l, int r) {
        if (l >= r) return 0;

        int mid = l + (r - l) / 2;
        long long cnt = 0;

        cnt += mergeSort(pref, l, mid);
        cnt += mergeSort(pref, mid + 1, r);

        int i = l;

        for (int j = mid + 1; j <= r; j++) {
            while (i <= mid && pref[i] < pref[j])
                i++;

            cnt += (i - l);
        }

        vector<int> temp;
        int p1 = l, p2 = mid + 1;

        while (p1 <= mid && p2 <= r) {
            if (pref[p1] <= pref[p2])
                temp.push_back(pref[p1++]);
            else
                temp.push_back(pref[p2++]);
        }

        while (p1 <= mid) temp.push_back(pref[p1++]);
        while (p2 <= r) temp.push_back(pref[p2++]);

        for (int k = 0; k < temp.size(); k++)
            pref[l + k] = temp[k];

        return cnt;
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        return mergeSort(pref, 0, n);
    }
};
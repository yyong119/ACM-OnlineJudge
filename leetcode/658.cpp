class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(), pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        vector<int> ans;
        if (!pos)
            for (int i = 0; i < k; ++i)
                ans.push_back(arr[i]);
        else if (pos == n)
            for (int i = n - k; i < n; ++i)
                ans.push_back(arr[i]);
        else {
            int l, r;
            if (x - arr[pos - 1] <= arr[pos] - x) {
                l = pos - 1; r = pos - 1;
            }
            else {
                l = pos; r = pos;
            }
            if (k == 1)
                ans.push_back(arr[l]);
            else {
                while (r - l + 1 < k)
                    if (!l) ++r;
                    else if (r == n - 1) --l;
                    else if (arr[r + 1] - x < x - arr[l - 1]) ++r;
                    else --l;
                for (int i = l; i <= r; ++i)
                    ans.push_back(arr[i]);
            }
        }
        return ans;
    }
};

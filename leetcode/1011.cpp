class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int n = weights.size();
        if (n == 1) return weights[0];
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        while (l < r) {
            int mid = (l + r) >> 1;
            int k = 1, cur_weight = 0;
            for (int i = 0; i < n; ++i)
                if (cur_weight + weights[i] > mid) {
                    cur_weight = weights[i];
                    ++k;
                }
                else
                    cur_weight += weights[i];
            if (k <= D)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

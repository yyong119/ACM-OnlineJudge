class Solution {
public:
    bool check(const vector<int>& piles, int n, int s, int H) {
        int time = 0;
        for (int i = 0; i < n; ++i)
            time += (piles[i] - 1) / s + 1;
        if (time <= H) return true;
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int H) {
        int n = piles.size(), l = 1, r = 0;
        for (int i = 0; i < n; ++i) r = max(r, piles[i]);
        if (H == n) return r;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (check(piles, n, mid, H)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
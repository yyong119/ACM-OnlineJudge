class Solution {
public:
    int minSteps(int n) {
        int p = n, ans = 0;
        while (p > 1) {
            int k = 2;
            while (p % k) ++k;
            ans += k;
            p /= k;
        }
        return ans;
    }
};

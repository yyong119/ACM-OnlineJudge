class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int a[33],b[33];
        memset(a, 0, sizeof(a)); memset(b, 0, sizeof(b));
        int ans = 0, p = 0, q = 0;
        while (m) {
            a[p++] = m & 1;
            m >>= 1;
        }
        while(n) {
            b[q++] = n & 1;
            n >>= 1;
        }
        for (int i = 32; i >= 0; --i)
            if (a[i] == b[i]) {
                if (a[i])
                    ans += (1 << i);
            }
            else break;
        return ans;
    }
};
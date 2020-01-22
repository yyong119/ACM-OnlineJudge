class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int ans = 0, l = 0, r = K - 1, n = A.size(), cur_flip = 0;
        int B[n]; memset(B, 0, sizeof(B));
        while (r < n) {
            B[r] = -cur_flip;
            if ((A[l] + B[l] + cur_flip) % 2 == 0) { // B[l] + cur_flip: the number of times that l-th number flipped
                ++ans;
                ++cur_flip;
            }
            ++l; ++r;
        }
        for (int i = l; i < n; ++i)
            if ((A[i] + B[i] + cur_flip) % 2 == 0)
                return -1;
        return ans;
    }
};
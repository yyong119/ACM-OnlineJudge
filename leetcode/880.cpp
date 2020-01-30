class Solution {
public:
    string decodeAtIndex(string S, int K) {
        int i;
        long long full_len = 0;
        string ans;
        for (i = 0; i < S.length(); ++i) {
            if (S[i] >= 'a' && S[i] <= 'z') {
                if (++full_len == K) {
                    ans = S[i];
                    return ans;
                }
            }
            else {
                full_len *= S[i] - '0';
                if (full_len >= K) break;
            }
        }
        while (i >= 0) {
            if (S[i] >= '2' && S[i] <= '9') {
                full_len /= S[i] - '0';
                K %= full_len;
                if (!K) {
                    while (S[i] >= '2' && S[i] <= '9')
                        --i;
                    ans = S[i];
                    break;
                }
            }
            else if (K == full_len--) {
                ans = S[i];
                break;
            }
            --i;
        }
        return ans;
    }
};

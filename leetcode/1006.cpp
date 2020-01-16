class Solution {
public:
    int clumsy(int N) {
        int a[4] = {1, 2, 2, -1};
        if (N > 4)
            return N + a[N % 4];
        else if (N > 2)
            return N + 3;
        else
            return N;
    }
};
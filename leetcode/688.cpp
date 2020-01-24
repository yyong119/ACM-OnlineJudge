class Solution {
public:
    struct Node {
        int steps, x, y;
        Node(int d, int p, int q) : steps(d), x(p), y(q) {}
    };
    const int actions[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
                                {1, -2}, {2, -1}, {2, 1}, {1, 2}};
    double knightProbability(int N, int K, int r, int c) {
        if (!K) return (double)1;
        double f[N][N][K + 1]; memset(f, 0, sizeof(f));
        f[r][c][0] = 1;
        for (int k = 0; k < K; ++k)
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    if (f[i][j][k])
                        for (int l = 0; l < 8; ++l) {
                            int x = i + actions[l][0], y = j + actions[l][1];
                            if (x >= 0 && x < N && y >= 0 && y < N)
                                f[x][y][k + 1] += f[i][j][k];
                        }
        double cnt = 0;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cnt += f[i][j][K];
        return cnt * pow(1.0 / 8.0, K);
    }
};
class Solution {
public:
    static inline bool cmp(vector<int>& a,vector<int>& b){
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if (!n) return 0;
        sort(points.begin(), points.end(), cmp);
        int t = points[0][1], cnt = 1;
        for (int i = 1; i < n; ++i)
            if (points[i][0] > t) {
                t = points[i][1];
                ++cnt;
            }
        return cnt;
    }
};
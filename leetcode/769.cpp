class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<vector<int>> intervals;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            vector<int> tmp = {min(i, arr[i]), max(i, arr[i])};
            intervals.push_back(tmp);
        }
        sort(intervals.begin(), intervals.end());
        int ans = 1, l = intervals[0][0], r = intervals[0][1];
        for (int i = 1; i < n; ++i)
            if (intervals[i][0] > r) {
                ++ans;
                l = intervals[i][0];
                r = intervals[i][1];
            }
            else
                r = max(r, intervals[i][1]);
        return ans;
    }
};
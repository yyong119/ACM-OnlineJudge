class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        int n = intervals.size();
        
        for (int i = 1; i < n; ++i)
            if (intervals[i][0] >= result.back()[0] && intervals[i][1] <= result.back()[1])                         continue;
            else
                result.push_back(intervals[i]);

        return result.size();
    }
};
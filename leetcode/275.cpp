class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if (n == 0 || n == 1 && !citations[0]) return 0;
        int l = 0, r = n - 1, mid, h;
        while (l < r - 1) {
            mid = (l + r) >> 1;
            h = n - mid;
            if (citations[mid] < h) l = mid + 1;
            else r = mid;
        }
        cout << l << " " << r << endl;
        h = n - l;
        if (citations[l] >= h) return h;
        h = n - r;
        if (citations[r] >= h) return h;
        return 0;
    }
};
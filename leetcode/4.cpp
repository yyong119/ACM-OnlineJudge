class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size(), pos1 = 0, pos2 = 0;
        int pre = 0, cur = 0;
        for (int i = 0; i <= (len >> 1); ++i) {
            
            pre = cur;
            if (pos1 < nums1.size() && pos2 < nums2.size()) {
                if (nums1[pos1] < nums2[pos2]) cur = nums1[pos1++];
                else cur = nums2[pos2++];
            }
            else if (pos1 == nums1.size())
                cur = nums2[pos2++];
            else cur = nums1[pos1++];
        }
        double ans = 0;
        if (len & 1 == 1) ans = cur;
        else return ans = (pre + cur) / 2.0;
        return ans;
    }
};
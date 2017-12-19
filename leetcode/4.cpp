#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<double> tmp(len1 + len2);
        int bit = (len1 + len2 + 1) % 2;
        int median = (len1 + len2) / 2;
        int i = 0, j = 0;
        int tmp_index = -1;
        for(; i < len1 && j < len2;)
        {
            if(nums1[i] < nums2[j]) { tmp[++tmp_index] = nums1[i]; ++i; }
            else { tmp[++tmp_index] = nums2[j]; ++j; }
            if(tmp_index == median)
                return (tmp[tmp_index] + tmp[tmp_index-bit]) / 2.0;
        }
        if(i < len1) {
            for(; i < len1; ++i) {
                tmp[++tmp_index] = nums1[i];
                if(tmp_index == median)
                    return (tmp[tmp_index] + tmp[tmp_index-bit]) / 2.0;
            }
        }
        else if(j < len2) {
            for(; j < len2; ++j) {
                tmp[++tmp_index] = nums2[j];
                if(tmp_index == median)
                    return (tmp[tmp_index] + tmp[tmp_index-bit]) / 2.0;
            }
        }
    }
};
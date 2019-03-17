class Solution {
public:
    int trap(vector<int>& height) {
        
        int l = 0, r = height.size() - 1;
        if (r < 2) return 0;
        
        int l_max = height[l] , r_max = height[r], second;
        int ans = 0;
        while (l < r) {
            
            l_max = max(l_max, height[l]);
            r_max = max(r_max, height[r]);
            second = min(l_max, r_max);
            if(height[l] < height[r])
                ans += second - height[l++];
            else
                ans += second - height[r--];
        }
        return ans;
    }
};
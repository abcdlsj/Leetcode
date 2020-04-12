// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        int ans = 0, i = 0, j = height.size() - 1, lmax = height[0], rmax = height[height.size() - 1];
        while(i < j) {
            if(lmax < rmax) {
                ans += lmax - height[i];
                lmax = max(lmax, height[++i]);
            } else {
                ans += rmax - height[j];
                rmax = max(rmax, height[--j]);
            }
        }
        return ans;
    }
};

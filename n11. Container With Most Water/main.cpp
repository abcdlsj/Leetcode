// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, ans = 0;
        while(left < right) {
            if(height[left] < height[right]) {
                ans = max(ans, height[left] * (right - left));
                left++;
            } else {
                ans = max(ans, height[right] * (right - left));
                right--;
            }
        }
        return ans;
    }
};

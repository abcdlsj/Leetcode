// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums);
        int maxnum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i-1] + dp[i], dp[i]);
            maxnum = max(maxnum, dp[i]);
        }
        return maxnum;
    }
};

// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return -2147483648;
        vector<int> dp(nums); int MAX = dp[0];
        for(int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i], dp[i - 1] + dp[i]);
            MAX = max(MAX, dp[i]);
        }
        return MAX;        
    }
};

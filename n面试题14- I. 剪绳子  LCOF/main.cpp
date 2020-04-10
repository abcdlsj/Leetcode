// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1, 1);
        
        for(int i = 3; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));
            }
        }

        return dp[n];
    }
};

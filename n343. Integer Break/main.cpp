// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int integerBreak(int n) {
        // if(n == 2) return 1;
        // if(n == 3) return 2;
        // int ans = 1;
        // while(n > 4) {
        //     n -= 3;
        //     ans *= 3;
        // }
        // return ans * n;
        vector<int> dp(n + 1, 1);
        for(int i = 3; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                dp[i] = max(dp[i], max(j * dp[i - j], j * (i - j)));
            }
        }
        return dp[n];
    }
};

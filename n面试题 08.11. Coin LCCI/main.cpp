// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int waysToChange(int n) {
        vector<int> dp(n + 1), coins = {1, 5, 10, 25};
        dp[0] = 1;
        for(int i = 0; i < 4; i++) {
            for(int j = coins[i]; j <= n; j++) {
                dp[j] = (dp[j] + dp[j - coins[i]]) % 1000000007;
            }
        }
        return dp[n];
    }
};

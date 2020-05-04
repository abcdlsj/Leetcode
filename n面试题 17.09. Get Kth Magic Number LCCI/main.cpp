// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int getKthMagicNumber(int k) {
        // vector<int> dp(k + 1);
        // int p3 = 0, p5 = 0, p7 = 0;
        // dp[0] = 1;
        // if(k == 1) return dp[0];
        // for(int i = 1; i < k; i++) {
        //     dp[i] = min(dp[p3] * 3, min(dp[p5] * 5, dp[p7] * 7));
        //     if(dp[i] == dp[p3] * 3) p3++;
        //     if(dp[i] == dp[p5] * 5) p5++;
        //     if(dp[i] == dp[p7] * 7) p7++;
        // }
        // return dp[k - 1];
        if(k == 1) return 1;
        vector<int> dp(k);
        int p3 = 0, p5 = 0, p7 = 0;
        dp[0] = 1;
        for(int i = 1; i < k; i++) {
            dp[i] = min(dp[p3] * 3, min(dp[p5] * 5, dp[p7] * 7));
            if(dp[i] == dp[p3] * 3) p3++;
            if(dp[i] == dp[p5] * 5) p5++;
            if(dp[i] == dp[p7] * 7) p7++;
        }
        return dp[k - 1];
    }
};

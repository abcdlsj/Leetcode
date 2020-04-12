// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int> (N + 1, 0));
        
        for(int m = 1; m <= N; m++) {
            dp[0][m] = 0;
            for(int n = 1; n <= K; n++) {
                dp[n][m] = dp[n][m-1] + dp[n-1][m-1] + 1;
                if(dp[n][m] >= N) {
                    return m;
                }
            }
        }

        return N;
    }
};

// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() < 1 || matrix[0].size() < 1) return 0;
        int m = matrix.size(), n = matrix[0].size(), ans = 0;

        vector<vector<char>> dp(m + 1, vector<char> (n + 1, '0'));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(matrix[i-1][j-1] == '1') {
                    dp[i][j] = 1 + min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]);
                    ans = max(ans, dp[i][j] - '0');
                }
            }
        }
        return ans * ans;
    }
};

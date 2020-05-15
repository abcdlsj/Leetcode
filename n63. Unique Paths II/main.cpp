// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) return  0;
        int row = obstacleGrid.size(), col = obstacleGrid[0].size();
        vector<vector<long>> dp(row, vector<long> (col, 0));
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                } else {
                    if(i == 0 && j == 0) dp[i][j] = 1;
                    else if(i == 0) dp[i][j] = dp[i][j-1];
                    else if(j == 0) dp[i][j] = dp[i-1][j]; 
                    else dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[row-1][col-1];
    }
};

// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return;
        int row = (n - 2) / 2, col = (n - 1) / 2;
        for(int i = 0; i <= row; i++) {
            for(int j = 0; j <= col; j++) {
                swap(matrix[i][j], matrix[j][n - i -1]);
                swap(matrix[i][j], matrix[n - i - 1][n - j - 1]);
                swap(matrix[i][j], matrix[n - j - 1][i]);
            }
        }
    }
};

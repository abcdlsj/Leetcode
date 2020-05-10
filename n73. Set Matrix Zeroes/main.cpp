// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowlen = matrix.size(), colen = matrix[0].size();
        bool isrow = false, iscol = false;
        for(int i = 0; i < rowlen; i++) {
            if(matrix[i][0] == 0) {
                isrow = true;
                break;
            }
        }
        for(int i = 0; i < colen; i++) {
            if(matrix[0][i] == 0) {
                iscol = true;
                break;
            }
        }
        for(int i = 1; i < rowlen; i++) {
            for(int j = 1; j < colen; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < rowlen; i++) {
            if(matrix[i][0] == 0) {
                for(int j = 1; j < colen; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 1; j < colen; j++) {
            if(matrix[0][j] == 0) {
                for(int i = 1; i < rowlen; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(isrow) {
            for(int i = 0; i < rowlen; i++) {
                matrix[i][0] = 0;
            }
        }
        if(iscol) {
            for(int j = 0; j < colen; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};

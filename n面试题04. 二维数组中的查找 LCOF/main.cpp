// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target){
        if(matrix.size() == 0) return false;
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m - 1;
        while(j >= 0&& i < n) {
            if(target == matrix[i][j]) return true; 
            if(target < matrix[i][j]) j--;
            else ++i;
        } 
        return false;
    }
};

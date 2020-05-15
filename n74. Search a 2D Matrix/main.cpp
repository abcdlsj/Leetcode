// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;

        int m = matrix.size(), n = matrix[0].size();
        int begin = 0, mid, end = m * n - 1;
        while(begin < end) {
            mid = begin + (end - begin) / 2;
            if(matrix[mid / n][mid % n] < target) {
                begin = mid + 1;
            } else {
                end = mid;
            }
        }

        return matrix[begin / n][begin % n] == target;
    }
};

// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int> (n));
        int left = 0, right = n - 1, top = 0, bot = n - 1, step = 1;
        while(step <= n * n) {
            for(int i = left; i <= right; i++) res[top][i] = step++;
            top++;
            for(int i = top; i <= bot; i++) res[i][right] = step++;
            right--;
            for(int i = right; i >= left; i--) res[bot][i] = step++;
            bot--;
            for(int i = bot; i >= top; i--) res[i][left] = step++;
            left++;
        }

        return res;
    }
};

// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int movingCount(int m, int n, int k) {
        int res = 0;
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        dfs(vis, m, n, k, 0, 0, res);
        return res;
    }
    void dfs(vector<vector<bool>> &vis, int m, int n, int k, int i, int j, int &res) {
        if(i < 0 || i == m || j < 0 || j == n || vis[i][j] || (i % 10 + i / 10 + j % 10 + j / 10) > k) return;
        vis[i][j] = true;
        res ++;
        dfs(vis, m, n, k, i + 1, j, res);
        dfs(vis, m, n, k, i - 1, j, res);
        dfs(vis, m, n, k, i, j + 1, res);
        dfs(vis, m, n, k, i, j - 1, res);
    }
};

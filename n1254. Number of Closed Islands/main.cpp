// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    int val = 1;
                    dfs(grid, i, j, val);
                    ans += val;
                }
            }
        }

        return ans;

    }
    void dfs(vector<vector<int>> &grid, int i, int j, int &val) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
            val = 0;
            return;
        }

        if(grid[i][j] != 0) return;
        grid[i][j] = 1;

        dfs(grid, i + 1, j, val);
        dfs(grid, i - 1, j, val);
        dfs(grid, i, j - 1, val);
        dfs(grid, i, j + 1, val);
    }
};

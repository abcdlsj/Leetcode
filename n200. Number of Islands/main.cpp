// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    void infect(int i, int j, vector<vector<char>>& grid) {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||grid[i][j]!='1') return;
        else {
            grid[i][j] = '2';
            infect(i+1,j,grid);
            infect(i-1,j,grid);
            infect(i,j+1,grid);
            infect(i,j-1,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == '1') {
                    infect(i,j,grid);
                    res++;
                }

            }
        }
        return res;
    }
};

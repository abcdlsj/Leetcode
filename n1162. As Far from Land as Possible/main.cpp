// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int time = 0, land = 0, ocean = 0, N = grid.size();
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(grid[i][j] == 0) {
                    ocean ++;
                }
           }
        }
        vector<int> x = {-1, 1, 0, 0}, y = {0, 0, 1, -1};
        if(ocean == N*N || ocean == 0) return -1;
        while(ocean != 0) {
            time++;
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    if(grid[i][j] == time) {
                        for(int k = 0; k < 4; k++) {
                            if(i + x[k] >= 0 && i + x[k] < N && j + y[k] >= 0 && j + y[k] < N && grid[i + x[k]][j + y[k]] == 0) {
                                grid[i + x[k]][j + y[k]] = time + 1;
                                ocean --;
                            }
                        }
                    }
                }
            }
        }
        return time;
    }
};

// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> directionX = {0, 0, 1, -1, 1, 1, -1, -1};
        vector<int> directionY = {1, -1, 0, 0, 1, -1, 1, -1};
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                int cnt = 0;
                for(int k = 0; k < 8; k++) {
                    int x = i + directionX[k];
                    int y = j + directionY[k];
                    if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
                        continue;
                    }
                    if(board[x][y] % 10 == 1) {
                        cnt++;
                    }
                }
                if(board[i][j] == 1) {
                    if(cnt < 2 || cnt > 3) {
                        board[i][j] = 101;
                    }
                    if(cnt >= 2 && cnt <= 3) {
                        board[i][j] = 111;
                    }
                } else {
                    if(cnt == 3) {
                        board[i][j] = 110;
                    }
                }
            }
        }
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                board[i][j] = (board[i][j] % 100) / 10;
            }
        }
    }
};

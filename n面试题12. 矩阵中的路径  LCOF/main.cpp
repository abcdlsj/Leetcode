// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(backtrack(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool backtrack(vector<vector<char>> &board, int row, int col, string &target, int index) {
        if(index == target.size()) return true;
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || target[index] != board[row][col]) {
            return false;
        }

        board[row][col] = '*';
        if (backtrack(board, row + 1, col, target, index + 1) ||
            backtrack(board, row - 1, col, target, index + 1) ||
            backtrack(board, row, col + 1, target, index + 1) ||
            backtrack(board, row, col - 1, target, index + 1))
                return true;

        board[row][col] = target[index];
        return false;
    }
};

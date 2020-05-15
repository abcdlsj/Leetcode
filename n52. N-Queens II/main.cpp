// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    int totalNQueens(int n) {
        //use 51 plan
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        backtrack(res, board, 0);
        return res.size();
    }
    void backtrack(vector<vector<string>> &res, vector<string> &board, int row) {
        if(row == board.size()) {
            res.push_back(board);
            return;
        }

        for(int col = 0; col < board[0].size(); col++) {
            if(isVaild(board, row, col) == false) continue;
            board[row][col] = 'Q';
            backtrack(res, board, row + 1);
            board[row][col] = '.';
        }

    }
    bool isVaild(const vector<string>& board, int row, int col) {
        // 查看列冲突，固定列
        for(int i = 0; i < board.size(); i++) {
            if(board[i][col] == 'Q')
                return false;
        }

        for(int i = row - 1, j = col + 1; i >= 0 && j < board[0].size(); i--, j++) {
            if(board[i][j] == 'Q')
                return false;
        }

        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q')
                return false;
        }

        return true;
    }
};

# Sudoku Solver ***
- 题目地址: [https://leetcode-cn.com/problems/sudoku-solver](https://leetcode-cn.com/problems/sudoku-solver)
- 执行时间: 2304 ms
- 内存消耗: 322.6 MB
- 通过日期: 2020-05-10 21:45

## 题目内容
<p>编写一个程序，通过已填充的空格来解决数独问题。</p>

<p>一个数独的解法需<strong>遵循如下规则</strong>：</p>

<ol>
	<li>数字 <code>1-9</code> 在每一行只能出现一次。</li>
	<li>数字 <code>1-9</code> 在每一列只能出现一次。</li>
	<li>数字 <code>1-9</code> 在每一个以粗实线分隔的 <code>3x3</code> 宫内只能出现一次。</li>
</ol>

<p>空白格用 <code>'.'</code> 表示。</p>

<p><img src="http://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png"></p>

<p><small>一个数独。</small></p>

<p><img src="http://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png"></p>

<p><small>答案被标成红色。</small></p>

<p><strong>Note:</strong></p>

<ul>
	<li>给定的数独序列只包含数字 <code>1-9</code> 和字符 <code>'.'</code> 。</li>
	<li>你可以假设给定的数独只有唯一解。</li>
	<li>给定数独永远是 <code>9x9</code> 形式的。</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);    
    }
    bool backtrack(vector<vector<char>> &board, int row, int col) {
        if(col == 9) return backtrack(board, row + 1, 0);

        if(row == 9) return true;

        for(int i = row; i < 9; i++) {
            for(int j = col; j < 9; j++) {
                if(board[i][j] != '.') {
                    return backtrack(board, i, j + 1);
                }

                for(char ch = '1'; ch <= '9'; ch++) {
                    if(!isVaild(board, i, j, ch)) continue;

                    board[i][j] = ch;
                    if(backtrack(board, i, j + 1)) return true;
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return false;
    }
    bool isVaild(vector<vector<char>> board, int row, int col, char n) {
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == n) return false;
            if(board[i][col] == n) return false;
            if(board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == n) return false;
        }
        return true;
    }
};

```
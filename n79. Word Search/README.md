# Word Search **
- 题目地址: [https://leetcode-cn.com/problems/word-search](https://leetcode-cn.com/problems/word-search)
- 执行时间: 24 ms
- 内存消耗: 7.6 MB
- 通过日期: 2020-04-13 08:45

## 题目内容
<p>给定一个二维网格和一个单词，找出该单词是否存在于网格中。</p>

<p>单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。</p>



<p><strong>示例:</strong></p>

<pre>board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "<strong>ABCCED</strong>", 返回 <strong>true</strong>
给定 word = "<strong>SEE</strong>", 返回 <strong>true</strong>
给定 word = "<strong>ABCB</strong>", 返回 <strong>false</strong></pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>board</code> 和 <code>word</code> 中只包含大写和小写英文字母。</li>
	<li><code>1 <= board.length <= 200</code></li>
	<li><code>1 <= board[i].length <= 200</code></li>
	<li><code>1 <= word.length <= 10^3</code></li>
</ul>


## 解法
```cpp
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

```
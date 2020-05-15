# N-Queens ***
- 题目地址: [https://leetcode-cn.com/problems/n-queens](https://leetcode-cn.com/problems/n-queens)
- 执行时间: 12 ms
- 内存消耗: 7.3 MB
- 通过日期: 2020-04-30 09:14

## 题目内容
<p><em>n </em>皇后问题研究的是如何将 <em>n</em> 个皇后放置在 <em>n</em>×<em>n</em> 的棋盘上，并且使皇后彼此之间不能相互攻击。</p>

<p><img src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/8-queens.png"></p>

<p><small>上图为 8 皇后问题的一种解法。</small></p>

<p>给定一个整数 <em>n</em>，返回所有不同的 <em>n </em>皇后问题的解决方案。</p>

<p>每一种解法包含一个明确的 <em>n</em> 皇后问题的棋子放置方案，该方案中 <code>'Q'</code> 和 <code>'.'</code> 分别代表了皇后和空位。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 4
<strong>输出:</strong> [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
<strong>解释:</strong> 4 皇后问题存在两个不同的解法。
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><strong>皇后</strong>，是<a href="https://baike.baidu.com/item/%E5%9B%BD%E9%99%85%E8%B1%A1%E6%A3%8B" target="_blank">国际象棋</a>中的棋子，意味着<a href="https://baike.baidu.com/item/%E5%9B%BD%E7%8E%8B" target="_blank">国王</a>的妻子。皇后只做一件事，那就是“<a href="https://baike.baidu.com/item/%E5%90%83%E5%AD%90" target="_blank">吃子</a>”。当她遇见可以吃的棋子时，就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一到七步，可进可退。（引用自 <a href="https://baike.baidu.com/item/%E7%9A%87%E5%90%8E/15860305?fr=aladdin">百度百科 - 皇后</a> ）</li>
</ul>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        backtrack(res, board, 0);
        return res;
    }
    void backtrack(vector<vector<string>>& res, vector<string>& board, int row) {
        if(row == board.size()) {
            res.push_back(board);
            return;
        }
        for(int col = 0; col < board[0].size(); col++) {
            if(isVaild(board, row, col) == false) { continue; }
            board[row][col] = 'Q';
            backtrack(res, board, row + 1);
            board[row][col] = '.';
        }
    }
    bool isVaild(const vector<string>& board, int row, int col) {
        for(int i = 0; i < board.size(); i++) {
            if(board[i][col] == 'Q') {
                return false;
            }
        }
        // right-up
        for(int i = row - 1, j = col + 1; i >= 0 && j < board[0].size(); i--, j++) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        //left-up
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};

```
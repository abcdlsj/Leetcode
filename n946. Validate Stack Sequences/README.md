# Validate Stack Sequences **
- 题目地址: [https://leetcode-cn.com/problems/validate-stack-sequences](https://leetcode-cn.com/problems/validate-stack-sequences)
- 执行时间: 24 ms
- 内存消耗: 15.2 MB
- 通过日期: 2020-04-27 20:44

## 题目内容
<p>给定 <code>pushed</code> 和 <code>popped</code> 两个序列，每个序列中的 <strong>值都不重复</strong>，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 <code>true</code>；否则，返回 <code>false</code> 。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
<strong>输出：</strong>true
<strong>解释：</strong>我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
<strong>输出：</strong>false
<strong>解释：</strong>1 不能在 2 之前弹出。
</pre>



<p><strong>提示：</strong></p>

<ol>
	<li><code>0 <= pushed.length == popped.length <= 1000</code></li>
	<li><code>0 <= pushed[i], popped[i] < 1000</code></li>
	<li><code>pushed</code> 是 <code>popped</code> 的排列。</li>
</ol>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack; int popidx = 0;
        for(int i = 0; i < pushed.size(); i++) {
            stack.push(pushed[i]);
            while(!stack.empty() && stack.top() == popped[popidx]) {
                popidx++;
                stack.pop();
            }
        }
        return stack.empty();
    }
};

```
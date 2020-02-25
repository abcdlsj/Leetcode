# Sum Lists LCCI **
- 题目地址: [https://leetcode-cn.com/problems/sum-lists-lcci](https://leetcode-cn.com/problems/sum-lists-lcci)
- 执行时间: 40 ms
- 内存消耗: 72.6 MB
- 通过日期: 2020-02-25 17:05

## 题目内容
<p>给定两个用链表表示的整数，每个节点包含一个数位。</p>
<p>这些数位是反向存放的，也就是个位排在链表首部。</p>
<p>编写函数对这两个整数求和，并用链表形式返回结果。</p>



<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
<strong>输出：</strong>2 -> 1 -> 9，即912
</pre>

<p><strong>进阶：</strong>假设这些数位是正向存放的，请再做一遍。</p>

<p><strong>示例：</strong></p>

<pre>
<strong>输入：</strong>(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
<strong>输出：</strong>9 -> 1 -> 2，即912
</pre>


## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *node = new ListNode(0);
    ListNode *curnode = node;
    int tmp = 0;
    while (l1 || l2 || tmp) {
      tmp = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + tmp;
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
      node->next = new ListNode(tmp % 10);
      tmp /= 10;
      node = node->next;
    }
    return curnode->next;
  }
};

```
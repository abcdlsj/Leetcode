# Add Two Numbers II **
- 题目地址: [https://leetcode-cn.com/problems/add-two-numbers-ii](https://leetcode-cn.com/problems/add-two-numbers-ii)
- 执行时间: 60 ms
- 内存消耗: 73.8 MB
- 通过日期: 2020-05-08 15:38

## 题目内容
<p>给你两个 <strong>非空 </strong>链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。</p>

<p>你可以假设除了数字 0 之外，这两个数字都不会以零开头。</p>



<p><strong>进阶：</strong></p>

<p>如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。</p>



<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
<strong>输出：</strong>7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stack1, stack2;
        while(l1 != NULL) {
            stack1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL) {
            stack2.push(l2->val);
            l2 = l2->next;
        }
        int car = 0,sum = 0;
        ListNode* l3 = NULL;
        while(!stack1.empty() || !stack2.empty() || car != 0) {
            int val1 = 0, val2 = 0;
            if(!stack1.empty()) {
                val1 = stack1.top();
                stack1.pop();
            }
            if(!stack2.empty()) {
                val2 = stack2.top();
                stack2.pop();
            }
            sum = val1 + val2 + car;
            ListNode* cur = new ListNode(sum % 10);
            car = sum / 10;
            cur->next = l3;
            l3 = cur;
        }
        return l3;
    }
};

```
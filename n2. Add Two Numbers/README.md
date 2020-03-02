# Add Two Numbers **
- 题目地址: [https://leetcode-cn.com/problems/add-two-numbers](https://leetcode-cn.com/problems/add-two-numbers)
- 执行时间: 36 ms
- 内存消耗: 72.5 MB
- 通过日期: 2020-03-01 00:06

## 题目内容
<p>给出两个 <strong>非空</strong> 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 <strong>逆序</strong> 的方式存储的，并且它们的每个节点只能存储 <strong>一位</strong> 数字。</p>

<p>如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。</p>

<p>您可以假设除了数字 0 之外，这两个数都不会以 0 开头。</p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>(2 -> 4 -> 3) + (5 -> 6 -> 4)
<strong>输出：</strong>7 -> 0 -> 8
<strong>原因：</strong>342 + 465 = 807
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
        ListNode* head = NULL, *cur = NULL;
        int pro = 0;
        while(l1 || l2) {
            int sum = pro;
            if(l1) {sum += l1->val;l1 = l1->next;}
            if(l2) {sum += l2->val;l2 = l2->next;}
            if(!cur) {
                cur = head = new ListNode(sum);
            }
            else {
                cur -> next = new ListNode(sum);
                cur = cur -> next;
            }
            if(cur -> val >= 10) {
                pro = 1;
                cur -> val = cur -> val - 10;
            }
            else pro = 0;
        }
        if (pro == 1) cur -> next = new ListNode(pro);
        return head;
    }
};

```
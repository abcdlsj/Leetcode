# Reverse Linked List II **
- 题目地址: [https://leetcode-cn.com/problems/reverse-linked-list-ii](https://leetcode-cn.com/problems/reverse-linked-list-ii)
- 执行时间: 4 ms
- 内存消耗: 6.5 MB
- 通过日期: 2020-04-29 22:24

## 题目内容
<p>反转从位置 <em>m</em> 到 <em>n</em> 的链表。请使用一趟扫描完成反转。</p>

<p><strong>说明:</strong><br>
1 ≤ <em>m</em> ≤ <em>n</em> ≤ 链表长度。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 1->2->3->4->5->NULL, <em>m</em> = 2, <em>n</em> = 4
<strong>输出:</strong> 1->4->3->2->5->NULL</pre>


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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(-1); dummy->next = head;
        ListNode* pre = dummy;
        for(int i = 1; i < m; i++) pre = pre->next;
        head = pre->next;
        for(int i = m; i < n; i++) {
            ListNode* node = head->next;
            head->next = node->next;
            node->next = pre->next;
            pre->next = node;
        }
        return dummy->next;
    }
};

```
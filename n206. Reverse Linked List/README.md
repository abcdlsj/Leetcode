# Reverse Linked List *
- 题目地址: [https://leetcode-cn.com/problems/reverse-linked-list](https://leetcode-cn.com/problems/reverse-linked-list)
- 执行时间: 12 ms
- 内存消耗: 10.5 MB
- 通过日期: 2020-03-03 16:46

## 题目内容
<p>反转一个单链表。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 1->2->3->4->5->NULL
<strong>输出:</strong> 5->4->3->2->1->NULL</pre>

<p><strong>进阶:</strong><br>
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？</p>


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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next == NULL) {
            return head;
        }
        ListNode *cur = reverseList(head->next);
        head->next->next = head;

        head -> next = NULL;

        return cur;
    }
};

```
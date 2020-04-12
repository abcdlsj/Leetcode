# Remove Nth Node From End of List **
- 题目地址: [https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list)
- 执行时间: 8 ms
- 内存消耗: 6.2 MB
- 通过日期: 2020-03-25 16:21

## 题目内容
<p>给定一个链表，删除链表的倒数第 <em>n </em>个节点，并且返回链表的头结点。</p>

<p><strong>示例：</strong></p>

<pre>给定一个链表: <strong>1->2->3->4->5</strong>, 和 <strong><em>n</em> = 2</strong>.

当删除了倒数第二个节点后，链表变为 <strong>1->2->3->5</strong>.
</pre>

<p><strong>说明：</strong></p>

<p>给定的 <em>n</em> 保证是有效的。</p>

<p><strong>进阶：</strong></p>

<p>你能尝试使用一趟扫描实现吗？</p>


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr;
        ListNode *fast = head, *slow = head;
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if(fast == nullptr) return slow->next;
        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};

```
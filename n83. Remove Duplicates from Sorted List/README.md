# Remove Duplicates from Sorted List *
- 题目地址: [https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list)
- 执行时间: 16 ms
- 内存消耗: 7.5 MB
- 通过日期: 2020-04-24 09:17

## 题目内容
<p>给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 1->1->2
<strong>输出:</strong> 1->2
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 1->1->2->3->3
<strong>输出:</strong> 1->2->3</pre>


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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        head->next = deleteDuplicates(head->next);
        if(head->val == head->next->val) head = head->next;
        return head;
    }
};

```
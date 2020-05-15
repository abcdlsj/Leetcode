# Merge Two Sorted Lists *
- 题目地址: [https://leetcode-cn.com/problems/merge-two-sorted-lists](https://leetcode-cn.com/problems/merge-two-sorted-lists)
- 执行时间: 12 ms
- 内存消耗: 7.2 MB
- 通过日期: 2020-05-01 11:35

## 题目内容
<p>将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 </p>

<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>1->2->4, 1->3->4
<strong>输出：</strong>1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            } else {
                l2->next = mergeTwoLists(l1, l2->next);
                return l2;
            }
        }
        if(l1 == NULL) return l2;
        return l1;
    }
};

```
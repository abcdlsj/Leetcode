# Merge Two Sorted Lists *
- 题目地址: [https://leetcode-cn.com/problems/merge-two-sorted-lists](https://leetcode-cn.com/problems/merge-two-sorted-lists)
- 执行时间: 16 ms
- 内存消耗: 7.1 MB
- 通过日期: 2020-04-20 20:54

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
    ListNode* mergeTwoLists(ListNode* i1, ListNode* i2) {;
        ListNode *i3 = new ListNode, *cur = i3;
        while(i1 && i2) {
            if(i1->val <= i2->val) {
                cur->next = i1;
                i1 = i1->next;
            } else {
                cur->next = i2;
                i2 = i2->next;
            }
            cur = cur->next;
        }
        if(i1 == nullptr) cur->next = i2;
        if(i2 == nullptr) cur->next = i1;
        return i3->next;
    }
};

```
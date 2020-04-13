# 合并两个排序的链表  LCOF *
- 题目地址: [https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof](https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof)
- 执行时间: 44 ms
- 内存消耗: 19.7 MB
- 通过日期: 2020-04-13 10:49

## 题目内容
<p>输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。</p>

<p><strong>示例1：</strong></p>

<pre><strong>输入：</strong>1->2->4, 1->3->4
<strong>输出：</strong>1->1->2->3->4->4</pre>

<p><strong>限制：</strong></p>

<p><code>0 <= 链表长度 <= 1000</code></p>

<p>注意：本题与主站 21 题相同：<a href="https://leetcode-cn.com/problems/merge-two-sorted-lists/">https://leetcode-cn.com/problems/merge-two-sorted-lists/</a></p>


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
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            } else {
                l2->next = mergeTwoLists(l1, l2->next);
                return l2;
            }
        }
        return l1;
    }
};

```
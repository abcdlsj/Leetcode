# Merge k Sorted Lists ***
- 题目地址: [https://leetcode-cn.com/problems/merge-k-sorted-lists](https://leetcode-cn.com/problems/merge-k-sorted-lists)
- 执行时间: 24 ms
- 内存消耗: 19.8 MB
- 通过日期: 2020-05-05 19:40

## 题目内容
<p>合并 <em>k </em>个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong>
[
  1->4->5,
  1->3->4,
  2->6
]
<strong>输出:</strong> 1->1->2->3->4->4->5->6</pre>


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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        return merge(lists, 0, lists.size() - 1);
    }
    ListNode* merge(vector<ListNode*>& lists, int begin, int end) {
        if(begin >= end) return lists[begin];

        int mid = begin + (end - begin) / 2;
        ListNode* leftLists = merge(lists, begin, mid);
        ListNode* rightLists = merge(lists, mid + 1, end);

        return merge2Lists(leftLists, rightLists);
    }
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode(-1), *cur = l3;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if(l1) cur->next = l1;
        if(l2) cur->next = l2;

        return l3->next;
    }
};

```
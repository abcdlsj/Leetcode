# Merge k Sorted Lists ***
- 题目地址: [https://leetcode-cn.com/problems/merge-k-sorted-lists](https://leetcode-cn.com/problems/merge-k-sorted-lists)
- 执行时间: 44 ms
- 内存消耗: 19.7 MB
- 通过日期: 2020-04-20 20:55

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
        int n = lists.size();
        if(n == 0) return NULL;
        return helper(lists, 0, n - 1);
    }
    ListNode* helper(vector<ListNode*>& lists, int left, int right) {
        if(left == right) {
            return lists[left];
        }
        int mid = left + (right - left) / 2;
        ListNode* leftlist = helper(lists, left, mid);
        ListNode* rightlist = helper(lists, mid + 1, right);
        return merge(leftlist, rightlist);
    }
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode, *cur = l3;
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
        if(l1 == NULL) cur->next = l2;
        if(l2 == NULL) cur->next = l1;
        return l3->next;
    }
};

```
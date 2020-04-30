# Sort List **
- 题目地址: [https://leetcode-cn.com/problems/sort-list](https://leetcode-cn.com/problems/sort-list)
- 执行时间: 92 ms
- 内存消耗: 29.8 MB
- 通过日期: 2020-04-24 20:44

## 题目内容
<p>在 <em>O</em>(<em>n</em> log <em>n</em>) 时间复杂度和常数级空间复杂度下，对链表进行排序。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 4->2->1->3
<strong>输出:</strong> 1->2->3->4
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> -1->5->3->4->0
<strong>输出:</strong> -1->0->3->4->5</pre>


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
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
    ListNode* mergesort(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *slow = head, *fast = head->next->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rightList = mergesort(slow->next);
        slow->next = NULL;
        ListNode* leftList = mergesort(head);
        return merge(leftList, rightList); 
    }
    ListNode* merge(ListNode* leftList, ListNode* rightList) {
        ListNode *head = new ListNode(-1), *cur = head;
        while(leftList != NULL && rightList != NULL) {
            if(leftList->val < rightList->val) {
                cur->next = leftList;
                leftList = leftList->next;
            } else {
                cur->next = rightList;
                rightList = rightList->next;
            }
            cur = cur->next;
        }
        if(leftList == NULL) cur->next = rightList;
        if(rightList == NULL) cur->next = leftList;
        return head->next;
    }
};

```
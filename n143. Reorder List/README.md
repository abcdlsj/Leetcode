# Reorder List **
- 题目地址: [https://leetcode-cn.com/problems/reorder-list](https://leetcode-cn.com/problems/reorder-list)
- 执行时间: 80 ms
- 内存消耗: 17.9 MB
- 通过日期: 2020-04-24 21:24

## 题目内容
<p>给定一个单链表 <em>L</em>：<em>L</em><sub>0</sub>→<em>L</em><sub>1</sub>→…→<em>L</em><sub><em>n</em>-1</sub>→<em>L</em><sub>n ，</sub><br>
将其重新排列后变为： <em>L</em><sub>0</sub>→<em>L</em><sub><em>n</em></sub>→<em>L</em><sub>1</sub>→<em>L</em><sub><em>n</em>-1</sub>→<em>L</em><sub>2</sub>→<em>L</em><sub><em>n</em>-2</sub>→…</p>

<p>你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。</p>

<p><strong>示例 1:</strong></p>

<pre>给定链表 1->2->3->4, 重新排列为 1->4->2->3.</pre>

<p><strong>示例 2:</strong></p>

<pre>给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.</pre>


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
    void reorderList(ListNode *head) {
        if(head==NULL || head->next == NULL) return;
        ListNode *slow = head, *fast = head, *cur = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *insertList= slow->next;
        slow->next = NULL;
        insertList = reverse(insertList);
        while(cur && insertList) {
            ListNode *insertNode = insertList, *curNext = cur->next;
            insertList = insertList->next;
            insertNode->next = cur->next;
            cur->next = insertNode;
            cur = curNext;
        }
    }

    ListNode *reverse(ListNode *head) {
        ListNode *pre = NULL, *cur = head;
        while(cur) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur; cur = tmp;
        }
        return pre;
    }
};

```
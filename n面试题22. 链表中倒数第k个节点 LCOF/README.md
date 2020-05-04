# 链表中倒数第k个节点 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof](https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof)
- 执行时间: 8 ms
- 内存消耗: 10.6 MB
- 通过日期: 2020-05-01 21:37

## 题目内容
<p>输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。</p>



<p><strong>示例：</strong></p>

<pre>给定一个链表: <strong>1->2->3->4->5</strong>, 和 <em>k </em><strong>= 2</strong>.

返回链表 4<strong>->5</strong>.</pre>


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
    ListNode* getKthFromEnd(ListNode* pListHead, int k) {
        if(pListHead == NULL || k == 0) return NULL;
        ListNode *slow = pListHead, *fast = pListHead;
        for(int i = 1; i < k && fast; i++) fast = fast->next;
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast == NULL ? NULL : slow;
    }
};

```
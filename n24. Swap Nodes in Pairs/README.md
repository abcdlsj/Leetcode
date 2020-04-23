# Swap Nodes in Pairs **
- 题目地址: [https://leetcode-cn.com/problems/swap-nodes-in-pairs](https://leetcode-cn.com/problems/swap-nodes-in-pairs)
- 执行时间: 4 ms
- 内存消耗: 6.6 MB
- 通过日期: 2020-04-23 16:03

## 题目内容
<p>给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。</p>

<p><strong>你不能只是单纯的改变节点内部的值</strong>，而是需要实际的进行节点交换。</p>



<p><strong>示例:</strong></p>

<pre>给定 <code>1->2->3->4</code>, 你应该返回 <code>2->1->4->3</code>.
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *node = head->next;
        head->next = swapPairs(node->next);
        node->next = head;
        return node;
    }
};

```
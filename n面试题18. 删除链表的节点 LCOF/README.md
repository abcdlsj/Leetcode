# 删除链表的节点 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof](https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof)
- 执行时间: 20 ms
- 内存消耗: 9.6 MB
- 通过日期: 2020-04-13 08:56

## 题目内容
<p>给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。</p>

<p>返回删除后的链表的头节点。</p>

<p><strong>注意：</strong>此题对比原题有改动</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> head = [4,5,1,9], val = 5
<strong>输出:</strong> [4,1,9]
<strong>解释: </strong>给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> head = [4,5,1,9], val = 1
<strong>输出:</strong> [4,5,9]
<strong>解释: </strong>给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
</pre>



<p><strong>说明：</strong></p>

<ul>
	<li>题目保证链表中节点的值互不相同</li>
	<li>若使用 C 或 C++ 语言，你不需要 <code>free</code> 或 <code>delete</code> 被删除的节点</li>
</ul>


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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *cur = head, *pre = NULL;
        if(cur == NULL) return head;
        if(cur->val == val) return head->next;
        while(cur && cur->val != val) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};

```
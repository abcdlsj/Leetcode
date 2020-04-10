# Linked List Cycle II **
- 题目地址: [https://leetcode-cn.com/problems/linked-list-cycle-ii](https://leetcode-cn.com/problems/linked-list-cycle-ii)
- 执行时间: 12 ms
- 内存消耗: 8.9 MB
- 通过日期: 2020-03-23 14:45

## 题目内容
<p>给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 <code>null</code>。</p>

<p>为了表示给定链表中的环，我们使用整数 <code>pos</code> 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 <code>pos</code> 是 <code>-1</code>，则在该链表中没有环。</p>

<p><strong>说明：</strong>不允许修改给定的链表。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>head = [3,2,0,-4], pos = 1
<strong>输出：</strong>tail connects to node index 1
<strong>解释：</strong>链表中有一个环，其尾部连接到第二个节点。
</pre>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist.png" style="height: 97px; width: 300px;"></p>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>head = [1,2], pos = 0
<strong>输出：</strong>tail connects to node index 0
<strong>解释：</strong>链表中有一个环，其尾部连接到第一个节点。
</pre>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test2.png" style="height: 74px; width: 141px;"></p>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>head = [1], pos = -1
<strong>输出：</strong>no cycle
<strong>解释：</strong>链表中没有环。
</pre>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/07/circularlinkedlist_test3.png" style="height: 45px; width: 45px;"></p>



<p><strong>进阶：</strong><br>
你是否可以不用额外空间解决此题？</p>


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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *fast= head, *slow = head;
        while(fast != NULL && fast->next !=NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) break;
        }
        if(fast == slow) fast = head;
        else return NULL;
        while(fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};

```
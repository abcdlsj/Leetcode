# 反转链表 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof)
- 执行时间: 16 ms
- 内存消耗: 8.6 MB
- 通过日期: 2020-04-13 10:46

## 题目内容
<p>定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。</p>



<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 1->2->3->4->5->NULL
<strong>输出:</strong> 5->4->3->2->1->NULL</pre>



<p><strong>限制：</strong></p>

<p><code>0 <= 节点个数 <= 5000</code></p>



<p><strong>注意</strong>：本题与主站 206 题相同：<a href="https://leetcode-cn.com/problems/reverse-linked-list/">https://leetcode-cn.com/problems/reverse-linked-list/</a></p>


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
    ListNode* reverseList(ListNode* head) {
        // ListNode *cur = head, *pre = NULL, *tmp;
        // while(cur != NULL) {
        //     tmp = cur->next;
        //     cur->next = pre;
        //     pre = cur;
        //     cur = tmp;
        // }
        // return pre;
        if(head == NULL || head->next == NULL) return head;
        
        ListNode *cur = reverseList(head->next);
        
        head->next->next = head;
        head->next = NULL;

        return cur;
    }
};

```
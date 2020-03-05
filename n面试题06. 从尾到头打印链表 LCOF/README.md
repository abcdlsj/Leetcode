# 从尾到头打印链表 LCOF *
- 题目地址: [https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof](https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof)
- 执行时间: 8 ms
- 内存消耗: 11.4 MB
- 通过日期: 2020-03-05 17:15

## 题目内容
<p>输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。</p>



<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>head = [1,3,2]
<strong>输出：</strong>[2,3,1]</pre>



<p><strong>限制：</strong></p>

<p><code>0 <= 链表长度 <= 10000</code></p>


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
        if(head -> next == NULL || head == NULL) return head;
        
        ListNode *cur = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        
        return cur;
    }
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        if(head == NULL) return res;
        ListNode* reverseHead = reverseList(head);
        while(reverseHead) {
            res.push_back(reverseHead -> val);
            reverseHead = reverseHead -> next;
        }
        return res;
    }
};

```
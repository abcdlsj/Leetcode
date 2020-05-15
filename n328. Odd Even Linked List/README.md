# Odd Even Linked List **
- 题目地址: [https://leetcode-cn.com/problems/odd-even-linked-list](https://leetcode-cn.com/problems/odd-even-linked-list)
- 执行时间: 12 ms
- 内存消耗: 10.7 MB
- 通过日期: 2020-05-10 07:47

## 题目内容
<p>给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。</p>

<p>请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入:</strong> 1->2->3->4->5->NULL
<strong>输出:</strong> 1->3->5->2->4->NULL
</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入:</strong> 2->1->3->5->6->4->7->NULL 
<strong>输出:</strong> 2->3->6->7->1->5->4->NULL</pre>

<p><strong>说明:</strong></p>

<ul>
	<li>应当保持奇数节点和偶数节点的相对顺序。</li>
	<li>链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。</li>
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;  
        ListNode *oddHead = head, *rtOdd = head, *evenHead = head->next, *rtEven = head->next;
        head = head->next->next;
        int index = 3;
        while(head != NULL) {
            if(index % 2 == 0) {
                evenHead->next = head;
                evenHead = evenHead->next;
            } else {
                oddHead->next = head;
                oddHead = oddHead->next;
            }
            index++;
            head = head->next;
        }
        evenHead->next = NULL, oddHead->next = rtEven;
        return rtOdd;
    }
};

```
# Remove Duplicate Node LCCI *
- 题目地址: [https://leetcode-cn.com/problems/remove-duplicate-node-lcci](https://leetcode-cn.com/problems/remove-duplicate-node-lcci)
- 执行时间: 68 ms
- 内存消耗: 17 MB
- 通过日期: 2020-04-24 08:59

## 题目内容
<p>编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。</p>

<p> <strong>示例1:</strong></p>

<pre>
<strong> 输入</strong>：[1, 2, 3, 3, 2, 1]
<strong> 输出</strong>：[1, 2, 3]
</pre>

<p> <strong>示例2:</strong></p>

<pre>
<strong> 输入</strong>：[1, 1, 1, 1, 2]
<strong> 输出</strong>：[1, 2]
</pre>

<p><strong>提示：</strong></p>

<ol>
<li>链表长度在[0, 20000]范围内。</li>
<li>链表元素在[0, 20000]范围内。</li>
</ol>

<p> <strong>进阶：</strong></p>

<p>如果不得使用临时缓冲区，该怎么解决？</p>


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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if(head == nullptr) return head;
        ListNode *cur = head;
        unordered_set<int> set;
        set.insert(head->val);
        while(cur->next) {
            if(set.find(cur->next->val) != set.end()) {
                cur->next = cur->next->next;
            } else {
                set.insert(cur->next->val);
                cur = cur->next;
            }
        }
        return head;
    }
};

```
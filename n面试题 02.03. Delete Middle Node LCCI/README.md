# Delete Middle Node LCCI *
- 题目地址: [https://leetcode-cn.com/problems/delete-middle-node-lcci](https://leetcode-cn.com/problems/delete-middle-node-lcci)
- 执行时间: 20 ms
- 内存消耗: 7.9 MB
- 通过日期: 2020-05-15 11:07

## 题目内容
<p>实现一种算法，删除单向链表中间的某个节点（即不是第一个或最后一个节点），假定你只能访问该节点。</p>



<p><strong>示例：</strong></p>

<pre><strong>输入：</strong>单向链表a->b->c->d->e->f中的节点c
<strong>结果：</strong>不返回任何数据，但该链表变为a->b->d->e->f
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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

```
# 复杂链表的复制  LCOF **
- 题目地址: [https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof](https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof)
- 执行时间: 12 ms
- 内存消耗: 11.3 MB
- 通过日期: 2020-04-28 13:10

## 题目内容
<p>请实现 <code>copyRandomList</code> 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 <code>next</code> 指针指向下一个节点，还有一个 <code>random</code> 指针指向链表中的任意节点或者 <code>null</code>。</p>



<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/09/e1.png"></p>

<pre><strong>输入：</strong>head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
<strong>输出：</strong>[[7,null],[13,0],[11,4],[10,2],[1,0]]
</pre>

<p><strong>示例 2：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/09/e2.png"></p>

<pre><strong>输入：</strong>head = [[1,1],[2,1]]
<strong>输出：</strong>[[1,1],[2,1]]
</pre>

<p><strong>示例 3：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/09/e3.png"></strong></p>

<pre><strong>输入：</strong>head = [[3,null],[3,0],[3,null]]
<strong>输出：</strong>[[3,null],[3,0],[3,null]]
</pre>

<p><strong>示例 4：</strong></p>

<pre><strong>输入：</strong>head = []
<strong>输出：</strong>[]
<strong>解释：</strong>给定的链表为空（空指针），因此返回 null。
</pre>



<p><strong>提示：</strong></p>

<ul>
	<li><code>-10000 <= Node.val <= 10000</code></li>
	<li><code>Node.random</code> 为空（null）或指向链表中的节点。</li>
	<li>节点数目不超过 1000 。</li>
</ul>



<p><strong>注意：</strong>本题与主站 138 题相同：<a href="https://leetcode-cn.com/problems/copy-list-with-random-pointer/">https://leetcode-cn.com/problems/copy-list-with-random-pointer/</a></p>




## 解法
```cpp
// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;

        for(Node *node = head, *copy = NULL; node != NULL; node = node->next->next) {
            copy = new Node(node->val);
            copy->next = node->next;
            node->next = copy;
        }

        for(Node *node = head; node != NULL; node = node->next->next) {
            if(node->random != NULL) {
                node->next->random = node->random->next;
            }
        }

        Node *newhead = head->next;
        for(Node *node = head, *tmp = NULL; node != NULL && node->next != NULL;) {
            tmp = node->next;
            node->next = tmp->next;
            node = tmp;
        }
        return newhead;
    }
};

```
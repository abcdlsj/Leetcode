# Convert Sorted List to Binary Search Tree **
- 题目地址: [https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree)
- 执行时间: 1028 ms
- 内存消耗: 354.1 MB
- 通过日期: 2020-02-24 11:37

## 题目内容
<p>给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。</p>

<p>本题中，一个高度平衡二叉树是指一个二叉树<em>每个节点 </em>的左右两个子树的高度差的绝对值不超过 1。</p>

<p><strong>示例:</strong></p>

<pre>给定的有序链表： [-10, -3, 0, 5, 9],

一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> getvec(ListNode* head){
        vector<int> ret;
        while(head){
            ret.push_back(head->val);
            head = head -> next;
        }
        return ret;
    }
    TreeNode* buildtree(vector<int> nums,int left,int right){
        if(left>=right) return NULL;
        int mid = (left+right) >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = buildtree(nums,left,mid);
        root -> right = buildtree(nums,mid+1,right);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> list = getvec(head);
        TreeNode* ret = buildtree(list,0,list.size());
        return ret;
    }
};

```
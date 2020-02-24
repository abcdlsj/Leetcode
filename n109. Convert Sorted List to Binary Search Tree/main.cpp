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

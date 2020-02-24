// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

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
    TreeNode* dfs(vector<int> &nums,int left,int right){
        if(left>=right) return NULL;
        int mid = (left + right) >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = dfs(nums,left,mid);
        root -> right = dfs(nums,mid+1,right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        return dfs(nums,0,len);
    }
};

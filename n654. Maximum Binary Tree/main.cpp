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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildhelper(nums, 0, nums.size() - 1);
    }
    TreeNode* buildhelper(vector<int> &nums, int begin, int end) {
        if(begin > end) return NULL;
        int maxnum = INT_MIN, maxpos = -1;
        for(int i = begin; i <= end; i++) {
            if(nums[i] > maxnum) {
                maxnum = nums[i];
                maxpos = i;
            }
        }
        TreeNode* node = new TreeNode(maxnum);
        node->left = buildhelper(nums, begin, maxpos - 1);
        node->right = buildhelper(nums, maxpos + 1, end);
        return node;
    }
};

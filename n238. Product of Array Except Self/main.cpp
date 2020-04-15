// Author: abcdlsj @ https://github.com/abcdlsj/Leetcode

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        for(int i = 0, left = 1; i < nums.size(); left *= nums[i], i++) {
            res[i] = left;
        }
        for(int i = nums.size() - 1, right = 1; i >= 0; right *= nums[i], i--) {
            res[i] *= right;
        }
        return res;
    }
};
